// Synthetic safe output slack only, outside the80B production owner. This lets
// an entire28-sample block overwrite high-window bytes without corrupting a
// different C++ owner. It is not an inferred original read-window capacity.
#include "audio_nibble_decoders_512.hpp"
#include "nibble_memory_512.hpp"
#pragma section(".niph$b",read,write)
__declspec(align(16)) __declspec(allocate(".niph$b")) static B high_output_slack512[192]{};
namespace decoder512 {
using namespace nibble512;
alignas(16) static B memory[4096];
static B* code;
static U calls=0,which=0,header=0,count=1,pattern=0,alias=0,history2=0;
static U mxround=0,flush=0,denorm=0,mxflags=0,xflags=0,original_lookup=0;
static const U specials[]={0,0x80000000,1,0x80000001,0x007fffff,0x00800000,
 0x3f800001,0xbf123456,0x7f7fffff,0x7f800000,0xff800000,0x7fc12345,0x7f812345,0xff812346};
struct Snapshot {B memory[4096],high[272],lookup[1024];Fpu fp;U mxcsr,abi;};
static Snapshot expected,got;
static void raw_patch(U offset,U expected,U replacement){
 require(read(ptr(code)+offset)==expected,"decoder original operand");write(ptr(code)+offset,replacement);
}
static void setup(){
 require(ptr(high_output_slack512)==ptr(audio_nibble_read_window_005e3b28)+80,"high synthetic slack adjacency");
 require(ptr(audio_nibble_read_tail_006b0800)==ptr(audio_mixer_nibble_lookup_006b04c0)+832,"canonical tail adjacency832");
 require(std::memcmp(audio_nibble_read_window_005e3b28,raw_high512,80)==0,"original raw high window before reset");
 code=static_cast<B*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_EXECUTE_READWRITE));require(code!=nullptr,"decoder slab");
 std::memcpy(code,raw_x87512,sizeof(raw_x87512));std::memcpy(code+256,raw_sse512,sizeof(raw_sse512));
 // Exact absolute operands, checked before changing only their address transport.
 for(U offset: {0x32u,0x39u})raw_patch(offset,offset==0x32?0x5e3b38:0x5e3b28,ptr(audio_nibble_read_window_005e3b28)+(offset==0x32?16:0));
 for(U offset:{0x67u,0x86u})raw_patch(offset,0x6b04c0,ptr(audio_mixer_nibble_lookup_006b04c0));
 for(U offset:{0x51u,0x60u,0x72u,0x8fu})raw_patch(256+offset,offset==0x51||offset==0x8f?0x5e3b28:0x5e3b38,ptr(audio_nibble_read_window_005e3b28)+(offset==0x51||offset==0x8f?0:16));
 for(U offset:{0x69u,0x98u})raw_patch(256+offset,0x6b04c0,ptr(audio_mixer_nibble_lookup_006b04c0));
}
static U bit(U i){return pattern?specials[(i+pattern-1)%(sizeof(specials)/4)]:0x3e000001u+(i%13)*0x80001u;}
static U reset(){
 std::memset(memory,0xcd,sizeof(memory));std::memcpy(audio_nibble_read_window_005e3b28,raw_high512,80);std::memset(high_output_slack512,0x45,192);
 // Includes loader-zero tail through raw transport, never oversized typed indexing.
 for(U i=0;i<256;++i)write32(ptr(audio_mixer_nibble_lookup_006b04c0)+i*4,bit(i));
 if(original_lookup){audio_mixer_initialize_nibble_table_0059b8d0();std::memset(audio_nibble_read_tail_006b0800,0,192);}
 if(pattern)for(U i=0;i<20;++i)write32(ptr(audio_nibble_read_window_005e3b28)+i*4,bit(i+3));
 U state=ptr(memory)+64,input=ptr(memory)+256,output=ptr(memory)+1024;
 if(alias==1)output=input; // compressed byte/output order, including lookahead
 if(alias==2)output=input-4;
 if(alias==3)output=state+24; // history-prefix writes alias state.output
 if(alias==4)input=ptr(audio_nibble_read_window_005e3b28);
 if(alias==5)output=ptr(audio_nibble_read_window_005e3b28)+8;
 if(alias==6){U offset=(header&15)*64;output=ptr(audio_mixer_nibble_lookup_006b04c0)+(offset>896?896:offset?offset:8);}
 if(alias==7)output=ptr(audio_mixer_nibble_lookup_006b04c0)+824; // crosses832
 if(alias==8)input=ptr(audio_mixer_nibble_lookup_006b04c0)+820;
 if(alias==9)state=ptr(memory)+1024-16; // prefix overwrites input/output fields
 // Header data is seeded before state, so deliberate state alias wins exactly.
 for(U i=0;i<64;++i)*reinterpret_cast<B*>(input+i)=static_cast<B>(i*29+0x31);
 *reinterpret_cast<B*>(input)=static_cast<B>(header);*reinterpret_cast<B*>(input+15)=static_cast<B>(header);
 write32(state,count);write32(state+4,alias==9?input:bit(pattern+7));write32(state+8,static_cast<I>(count)<=0?history2:bit(pattern+8));
 write32(state+12,input);write32(state+16,output);
 return state;
}
static void capture(Snapshot& s,U abi){
 std::memcpy(s.memory,memory,sizeof(memory));std::memcpy(s.high,audio_nibble_read_window_005e3b28,80);std::memcpy(s.high+80,high_output_slack512,192);
 for(U i=0;i<256;++i){U v=read32(ptr(audio_mixer_nibble_lookup_006b04c0)+i*4);std::memcpy(s.lookup+i*4,&v,4);}
 fpu(s.fp);s.mxcsr=rd(floating+24);s.abi=abi;
 // Only nonempty x87 values are architectural incoming/outgoing obligations;
 // empty-slot residue and FIP/FDP/opcode are intentionally not compared.
 const U top=(s.fp.status>>11)&7;
 for(U i=0;i<8;++i)if((s.fp.tag&(1u<<((top+i)&7)))==0)std::memset(s.fp.values+i*10,0,10);
}
static void execute(bool cpp,Snapshot& s){
 U state=reset(),result=0;void* fn=cpp?(which?reinterpret_cast<void*>(&audio_nibble_decode_sse_0059a660):reinterpret_cast<void*>(&audio_nibble_decode_x87_0059a5a0)):code+(which?256:0);
 seed();__asm fxsave floating
 floating[2]=static_cast<B>(floating[2]|xflags);__asm fxrstor floating
 U mx=0x1f80u|(mxround<<13)|(flush<<15)|(denorm<<6)|mxflags;__asm ldmxcsr mx
 U abi=invoke(fn,state,0,0,1,result);capture(s,abi);
}
static void check(){
 execute(false,expected);execute(true,got);
 if(got.abi||expected.abi||std::memcmp(&got,&expected,sizeof(got))){
  const B* a=reinterpret_cast<const B*>(&got);const B* b=reinterpret_cast<const B*>(&expected);U n=0;while(n<sizeof(got)&&a[n]==b[n])++n;
  std::printf("divergence decoder case=%u kernel=%u header=%02x count=%08x pattern=%u alias=%u hist2=%08x pc=%u rc=%u depth=%u mxrc=%u ftz=%u daz=%u flags=%x byte=%u %02x/%02x fp=%04x/%04x mx=%08x/%08x\n",calls,which,header,count,pattern,alias,history2,precision,rounding,depth,mxround,flush,denorm,mxflags,n,n<sizeof(got)?a[n]:0,n<sizeof(got)?b[n]:0,got.fp.status,expected.fp.status,got.mxcsr,expected.mxcsr);std::fflush(stdout);ExitProcess(1);
 }
 ++calls;
}
static void tests(){
 setup();precision=3;rounding=depth=0;
 original_lookup=1;
 for(which=0;which<2;++which)for(header=0;header<256;++header)for(U n:{1u,28u,29u,56u}){count=n;check();}
 original_lookup=0;count=1;
 for(which=0;which<2;++which)for(header=0;header<256;++header)for(pattern=1;pattern<=14;++pattern)check();
 for(which=0;which<2;++which)for(U pc:{0u,2u,3u})for(rounding=0;rounding<4;++rounding)for(U d:{0u,1u,4u,5u,6u,7u,8u})for(U flags:{0u,0x3fu})for(pattern=0;pattern<=14;pattern+=2){precision=pc;depth=d;header=0x29;xflags=flags;check();}
 precision=3;rounding=depth=xflags=0;
 which=1;header=0x29;
 for(mxround=0;mxround<4;++mxround)for(flush=0;flush<2;++flush)for(denorm=0;denorm<2;++denorm)for(U flags:{0u,0x3fu})for(pattern=1;pattern<=14;++pattern){mxflags=flags;check();}
 mxround=flush=denorm=mxflags=0;
 for(which=0;which<2;++which)for(alias=1;alias<=9;++alias)for(U h:{0u,0x29u,0x3cu,0x4du,0x8eu,0xbfu,0xffu})for(U p:{0u,5u,12u}){header=h;pattern=p;check();}
 alias=0;pattern=0;
 for(which=0;which<2;++which)for(U n:{0u,0xffffffffu,0x80000000u})for(U bits:{0u,0x80000000u,1u,2u,0xffffffffu}){count=n;history2=bits;check();}
 require(VirtualFree(code,0,MEM_RELEASE)!=0,"decoder slab release");
 std::printf("audio_nibble_decoders_original_x86_vs_cpp=PASS cases=%u all256headers=PASS physical_windows=PASS aliases=PASS mapped_nonpositive=PASS used_FP=PASS ABI=PASS\n",calls);
}
}
int main(){
 require(ptr(audio_nibble_read_tail_006b0800)==ptr(audio_mixer_nibble_lookup_006b04c0)+832,"initial tail adjacency");
 MEMORY_BASIC_INFORMATION m{};require(VirtualQuery(audio_mixer_nibble_lookup_006b04c0,&m,sizeof(m))==sizeof(m)&&((m.Protect&(PAGE_READWRITE|PAGE_WRITECOPY))!=0),"initial RW section");
 for(B b:audio_nibble_read_tail_006b0800)require(b==0,"production tail loader zero before reset");
 std::memset(audio_nibble_read_tail_006b0800,0x6d,192);
 regression486();
 for(B b:audio_nibble_read_tail_006b0800)require(b==0x6d,"original and C++ oldinitializer stop832");
 decoder512::tests();return 0;
}
