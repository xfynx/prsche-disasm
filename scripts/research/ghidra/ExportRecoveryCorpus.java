// Export the entire analyzed program, not selected gameplay slices.
// @category Porsche.V2
import ghidra.app.util.headless.HeadlessScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.MemoryBlock;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.io.*;
import java.util.*;

public class ExportRecoveryCorpus extends HeadlessScript {
    private final Gson json = new GsonBuilder().disableHtmlEscaping().create();
    private Map<String,Object> row(Object... pairs) {
        Map<String,Object> r = new LinkedHashMap<>();
        for (int i=0;i<pairs.length;i+=2) r.put((String)pairs[i],pairs[i+1]);
        return r;
    }
    private void write(BufferedWriter w, Object r) throws IOException {
        w.write(json.toJson(r)); w.write("\n");
    }
    private BufferedWriter writer(Path dir, String name) throws IOException {
        return Files.newBufferedWriter(dir.resolve(name), StandardCharsets.UTF_8);
    }
    @Override public void run() throws Exception {
        String[] args=getScriptArgs();
        if(args.length<2) throw new IllegalArgumentException("output-dir listing|decompile [timeout-seconds]");
        String mode=args[1];
        if(!mode.equals("listing") && !mode.equals("decompile")) throw new IllegalArgumentException("unknown mode");
        String nativePath=currentProgram.getExecutablePath();
        if(nativePath.length()>3 && nativePath.charAt(0)=='/' && nativePath.charAt(2)==':') nativePath=nativePath.substring(1);
        String sha=HexFormat.of().formatHex(MessageDigest.getInstance("SHA-256").digest(Files.readAllBytes(Path.of(nativePath))));
        String cachedSha=currentProgram.getExecutableSHA256();
        if(cachedSha!=null && !cachedSha.isEmpty() && !sha.equalsIgnoreCase(cachedSha))
            throw new IOException("Original file SHA differs from analyzed program: "+currentProgram.getName());
        Path dir=Path.of(args[0]).resolve(currentProgram.getName()+"-"+sha.substring(0,12));
        Files.createDirectories(dir);
        List<Function> functions=new ArrayList<>();
        Map<Address,Function> entries=new HashMap<>();
        for(Function f:currentProgram.getFunctionManager().getFunctions(true)) { functions.add(f); entries.put(f.getEntryPoint(),f); }
        if(mode.equals("listing")) {
            long instructionCount=0, instructionBytes=0;
            AddressSet classified=new AddressSet();
            try(BufferedWriter w=writer(dir,"disassembly.asm")) {
                w.write("; AUTOMATIC GHIDRA LISTING; original source/behavior not yet recovered\n; SHA256 "+sha+"\n");
                for(Instruction i:currentProgram.getListing().getInstructions(true)) {
                    monitor.checkCancelled();
                    Function f=entries.get(i.getAddress());
                    if(f!=null) w.write("\n; FUNCTION "+f.getEntryPoint()+" "+f.getName(true)+"\n");
                    w.write(i.getAddress()+"  "+HexFormat.of().formatHex(i.getBytes())+"  "+i.toString().stripTrailing()+"\n");
                    classified.add(i.getMinAddress(),i.getMaxAddress());
                    instructionCount++; instructionBytes+=i.getLength();
                }
            }
            try(BufferedWriter w=writer(dir,"functions.jsonl")) {
                for(Function f:functions) {
                    List<Object> ranges=new ArrayList<>();
                    for(AddressRange ar:f.getBody().getAddressRanges()) ranges.add(List.of(ar.getMinAddress().toString(),ar.getMaxAddress().toString()));
                    write(w,row("entry_va",f.getEntryPoint().toString(),"name",f.getName(true),"signature",f.getSignature().toString(),
                        "ranges",ranges,"body_bytes",f.getBody().getNumAddresses(),"thunk",f.isThunk(),"recovery_status","unrecovered"));
                }
            }
            long unclassifiedBytes=0, executableBytes=0;
            List<Object> blocks=new ArrayList<>();
            try(BufferedWriter gaps=writer(dir,"unclassified-executable.jsonl"); BufferedWriter data=writer(dir,"defined-data.jsonl")) {
                for(MemoryBlock b:currentProgram.getMemory().getBlocks()) {
                    blocks.add(row("name",b.getName(),"start",b.getStart().toString(),"end",b.getEnd().toString(),
                        "bytes",b.getSize(),"initialized",b.isInitialized(),"read",b.isRead(),"write",b.isWrite(),"execute",b.isExecute()));
                    if(!b.isExecute()) continue;
                    executableBytes+=b.getSize();
                    AddressSet missing=new AddressSet(b.getStart(),b.getEnd()).subtract(classified);
                    for(AddressRange ar:missing.getAddressRanges()) {
                        unclassifiedBytes+=ar.getLength();
                        write(gaps,row("start",ar.getMinAddress().toString(),"end",ar.getMaxAddress().toString(),
                            "bytes",ar.getLength(),"status","not-decoded-as-instructions; may be code, data or padding"));
                    }
                }
                for(Data d:currentProgram.getListing().getDefinedData(true)) {
                    monitor.checkCancelled();
                    Object value=d.getValue();
                    write(data,row("va",d.getAddress().toString(),"bytes",d.getLength(),"type",d.getDataType().getPathName(),
                        "value",value==null?null:value.toString()));
                }
            }
            Files.writeString(dir.resolve("listing.json"),json.toJson(row("schema",1,"module",currentProgram.getName(),"sha256",sha,
                "language",currentProgram.getLanguageID().toString(),"compiler_spec",currentProgram.getCompilerSpec().getCompilerSpecID().toString(),
                "image_base",currentProgram.getImageBase().toString(),"functions",functions.size(),"instructions",instructionCount,
                "instruction_bytes",instructionBytes,"executable_bytes",executableBytes,"unclassified_executable_bytes",unclassifiedBytes,
                "blocks",blocks,"complete_listing_of_analyzed_instructions",true,"complete_code_discovery",false))+"\n",StandardCharsets.UTF_8);
            println("V2_LISTING "+currentProgram.getName()+" instructions="+instructionCount+" functions="+functions.size()+" gaps="+unclassifiedBytes);
        } else {
            int timeout=args.length>2?Integer.parseInt(args[2]):30;
            Path finished=dir.resolve("decompilation.json");
            if(Files.exists(finished)) {
                Map old=json.fromJson(Files.readString(finished),Map.class);
                if(sha.equals(old.get("sha256")) && Boolean.TRUE.equals(old.get("attempted_all_functions"))
                        && ((Number)old.get("functions")).intValue()==functions.size()
                        && Files.exists(dir.resolve("decompiled.c")) && Files.exists(dir.resolve("decompile-status.jsonl"))) {
                    println("V2_DECOMPILE_SKIP "+currentProgram.getName()); return;
                }
            }
            DecompInterface decomp=new DecompInterface();
            decomp.toggleCCode(true);
            if(!decomp.openProgram(currentProgram)) throw new IOException("decompiler open failed: "+decomp.getLastMessage());
            long ok=0, failed=0, skipped=0;
            try(BufferedWriter c=writer(dir,"decompiled.c"); BufferedWriter status=writer(dir,"decompile-status.jsonl")) {
                c.write("/* AUTOMATIC GHIDRA PSEUDO-C. NOT A COMPILABLE RECOVERED SOURCE TREE.\n   Original SHA256 "+sha+" */\n");
                for(Function f:functions) {
                    monitor.checkCancelled();
                    String state, message="";
                    if(f.isExternal()) { state="external"; skipped++; }
                    else {
                        DecompileResults result=decomp.decompileFunction(f,timeout,monitor);
                        message=result.getErrorMessage();
                        if(result.decompileCompleted() && result.getDecompiledFunction()!=null) {
                            state="automatic-pseudo-c"; ok++;
                            String body=result.getDecompiledFunction().getC().replace("\r\n","\n").replaceAll("(?m)[\\t ]+$","").stripTrailing();
                            c.write("\n/* VA "+f.getEntryPoint()+" */\n"+body+"\n");
                        } else { state=result.isTimedOut()?"timeout":"failed"; failed++; }
                    }
                    write(status,row("entry_va",f.getEntryPoint().toString(),"name",f.getName(true),"status",state,"message",message));
                    if((ok+failed+skipped)%100==0) {
                        c.flush(); status.flush();
                        println("V2_PROGRESS "+currentProgram.getName()+" "+(ok+failed+skipped)+"/"+functions.size()+" failed="+failed);
                    }
                }
            } finally { decomp.dispose(); }
            Files.writeString(finished,json.toJson(row("schema",1,"module",currentProgram.getName(),"sha256",sha,
                "functions",functions.size(),"pseudo_c_functions",ok,"failed",failed,"external",skipped,
                "timeout_seconds_per_function",timeout,"attempted_all_functions",true,"compilable_source",false,
                "matched_functions",0,"matched_binary",false))+"\n",StandardCharsets.UTF_8);
            println("V2_DECOMPILED "+currentProgram.getName()+" ok="+ok+" failed="+failed);
        }
    }
}
