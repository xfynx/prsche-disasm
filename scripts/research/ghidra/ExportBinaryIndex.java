// Export analyzed program navigation, not claims about recovered game semantics.
// @category Porsche.Research
import ghidra.app.util.headless.HeadlessScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.mem.MemoryBlock;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.io.*;
import java.util.*;

public class ExportBinaryIndex extends HeadlessScript {
    private final Gson json = new GsonBuilder().disableHtmlEscaping().create();
    private Map<String,Object> row(Object... pairs) {
        Map<String,Object> r = new LinkedHashMap<>();
        for (int i=0; i<pairs.length; i+=2) r.put((String)pairs[i],pairs[i+1]);
        return r;
    }
    private void write(BufferedWriter w, Object r) throws IOException {
        w.write(json.toJson(r)); w.newLine();
    }
    private BufferedWriter writer(Path dir, String name) throws IOException {
        return Files.newBufferedWriter(dir.resolve(name), StandardCharsets.UTF_8);
    }
    private String addr(Address a) { return a == null ? null : a.toString(); }
    private String owner(Address a) {
        Function f = currentProgram.getFunctionManager().getFunctionContaining(a);
        return f == null ? null : addr(f.getEntryPoint());
    }
    @Override public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1) throw new IllegalArgumentException("Expected output directory");
        String executablePath = currentProgram.getExecutablePath();
        // Ghidra's PE loader stores Windows paths as /C:/..., not a native Path.
        if (executablePath.length()>3 && executablePath.charAt(0)=='/' && executablePath.charAt(2)==':')
            executablePath=executablePath.substring(1);
        String hash = HexFormat.of().formatHex(MessageDigest.getInstance("SHA-256")
            .digest(Files.readAllBytes(Path.of(executablePath))));
        Path dir = Path.of(args[0]).resolve(currentProgram.getName()+"-"+hash.substring(0,12));
        Files.createDirectories(dir);
        long functions=0, refs=0, calls=0, strings=0, symbols=0, instructions=0, codeBytes=0, unresolvedCalls=0;
        try (BufferedWriter w=writer(dir,"functions.jsonl")) {
            for (Function f: currentProgram.getFunctionManager().getFunctions(true)) {
                monitor.checkCancelled();
                List<List<String>> ranges = new ArrayList<>();
                for (AddressRange range: f.getBody().getAddressRanges())
                    ranges.add(Arrays.asList(addr(range.getMinAddress()),addr(range.getMaxAddress())));
                write(w,row("entry_va",addr(f.getEntryPoint()),"name",f.getName(true),
                    "signature",f.getSignature().toString(),"ranges",ranges,"body_bytes",f.getBody().getNumAddresses(),
                    "thunk",f.isThunk(),"external",f.isExternal(),"source",f.getSymbol().getSource().toString()));
                functions++;
            }
        }
        try (BufferedWriter w=writer(dir,"references.jsonl"); BufferedWriter c=writer(dir,"calls.jsonl")) {
            ReferenceIterator iterator=currentProgram.getReferenceManager().getReferenceIterator(currentProgram.getMinAddress());
            while(iterator.hasNext()) {
                monitor.checkCancelled();
                Reference r=iterator.next();
                Symbol target=currentProgram.getSymbolTable().getPrimarySymbol(r.getToAddress());
                Map<String,Object> record=row("from_va",addr(r.getFromAddress()),"to_va",addr(r.getToAddress()),
                    "from_function",owner(r.getFromAddress()),"to_function",owner(r.getToAddress()),
                    "type",r.getReferenceType().toString(),"source",r.getSource().toString(),
                    "target_symbol",target==null?null:target.getName(true));
                write(w,record); refs++;
                if(r.getReferenceType().isCall()) { write(c,record); calls++; }
            }
        }
        try (BufferedWriter w=writer(dir,"strings.jsonl")) {
            for(Data d:currentProgram.getListing().getDefinedData(true)) {
                monitor.checkCancelled();
                Object value=d.getValue();
                if(value instanceof String) {
                    write(w,row("va",addr(d.getAddress()),"value",value,"length",d.getLength(),
                        "type",d.getDataType().getName())); strings++;
                }
            }
        }
        try (BufferedWriter w=writer(dir,"symbols.jsonl")) {
            SymbolIterator iterator=currentProgram.getSymbolTable().getAllSymbols(true);
            while(iterator.hasNext()) {
                monitor.checkCancelled();
                Symbol s=iterator.next();
                write(w,row("va",addr(s.getAddress()),"name",s.getName(true),"type",s.getSymbolType().toString(),
                    "source",s.getSource().toString(),"external",s.isExternal())); symbols++;
            }
        }
        try (BufferedWriter w=writer(dir,"unresolved-calls.jsonl")) {
            for(Instruction i:currentProgram.getListing().getInstructions(true)) {
                monitor.checkCancelled(); instructions++; codeBytes+=i.getLength();
                if(i.getFlowType().isCall() && i.getFlows().length==0) {
                    write(w,row("va",addr(i.getAddress()),"function",owner(i.getAddress()),"instruction",i.toString()));
                    unresolvedCalls++;
                }
            }
        }
        List<Object> blocks = new ArrayList<>(); long executableBytes=0;
        for(MemoryBlock b:currentProgram.getMemory().getBlocks()) {
            blocks.add(row("name",b.getName(),"start_va",addr(b.getStart()),"end_va",addr(b.getEnd()),
                "bytes",b.getSize(),"execute",b.isExecute(),"initialized",b.isInitialized()));
            if(b.isExecute()) executableBytes+=b.getSize();
        }
        Object timedOut=isHeadlessAnalysisEnabled()?Boolean.valueOf(analysisTimeoutOccurred()):null;
        Path oldMetadata=dir.resolve("metadata.json");
        if(timedOut==null && Files.exists(oldMetadata))
            timedOut=json.fromJson(Files.readString(oldMetadata),Map.class).get("analysis_timed_out");
        Map<String,Object> metadata=row("schema",1,"file",currentProgram.getName(),"sha256",hash,
            "image_base",addr(currentProgram.getImageBase()),"language",currentProgram.getLanguageID().toString(),
            "analysis_timed_out",timedOut,"export_mode",isHeadlessAnalysisEnabled()?"analysis":"cached-analysis",
            "functions",functions,"references",refs,"calls",calls,
            "strings",strings,"symbols",symbols,"instructions",instructions,"instruction_bytes",codeBytes,
            "executable_bytes",executableBytes,"unresolved_calls",unresolvedCalls,"blocks",blocks,
            "boundary","Ghidra analysis discoveries; not proof of original runtime behavior or complete indirect targets");
        Files.writeString(dir.resolve("metadata.json"),json.toJson(metadata)+"\n",StandardCharsets.UTF_8);
        println("BINARY_INDEX "+json.toJson(metadata));
    }
}
