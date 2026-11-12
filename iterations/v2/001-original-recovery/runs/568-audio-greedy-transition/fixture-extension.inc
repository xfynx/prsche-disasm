// Bounded current-run scenes: raw 568 bodies and real 565/561/list/queue owners.
// Unused references from the canonical files.cpp TU fail closed in this fixture.
namespace porsche {
I __cdecl file_exists_00561b80(const char*){ExitProcess(90);return 0;}
U __cdecl file_device_name_00568e90(const char*){ExitProcess(90);return 0;}
void __cdecl file_start_device_00568390(U){ExitProcess(90);}
I __cdecl file_wait_00567f70(U){ExitProcess(90);return 0;}
void* __cdecl file_object_allocate_0056e5f0(U*){ExitProcess(90);return nullptr;}
U __cdecl file_object_free_0056e640(void*){ExitProcess(90);return 0;}
U __cdecl file_physical_close_00592290(void*){ExitProcess(90);return 0;}
void __cdecl file_format_005a0fbf(char*,const char*,const char*,const char*){ExitProcess(90);}
void __cdecl file_set_last_error(U){ExitProcess(90);}
}
static void prepare_group_scene(U object){
 std::memset(test_devices,0,sizeof test_devices);std::memset(test_ops,0,sizeof test_ops);
 devices_006a5c7c=test_devices;
 const U id=(scene==6)?0xfedcba1fu:(scene==3?1u:5u);const U index=id&31u;
 auto& dev=test_devices[index];dev.queued.key=operation_key_005684c0;
 dev.queued.lock=reinterpret_cast<void*>(0x17171717u);dev.completed.lock=reinterpret_cast<void*>(0x18181818u);
 dev.queued_event=reinterpret_cast<void*>(0x19191919u);
 test_ops[0].id=(scene==2)?id+32u:id;test_ops[0].group=0x41;
 if(scene!=0){dev.queued.count=1;dev.queued.head=dev.queued.tail=reinterpret_cast<IoNode*>(&test_ops[0]);}
 wr(reinterpret_cast<void*>(object+0x28),(scene==4)?2u:1u);
 wr(reinterpret_cast<void*>(object+0x30),0x876543abu);wr(reinterpret_cast<void*>(object+0x168),id);
 if(scene==3)devices_006a5c7c=reinterpret_cast<FileDevice*>(0xffffff90u);
}
int main(){
 SetErrorMode(SEM_FAILCRITICALERRORS|SEM_NOGPFAULTERRORBOX);AddVectoredExceptionHandler(1,&fault);
 require(devices_006a5c7c==nullptr,"canonical initial device pointer");
 const B* zero=reinterpret_cast<const B*>(&audio_stream_service_storage_006b7740);for(U i=0;i<80;++i)require(zero[i]==0,"initial slots");
 require(sizeof path_original==sizeof path_string&&!std::memcmp(path_original,path_string,sizeof path_original),"original path bytes");
 require(sizeof greedy_original==sizeof greedy_message&&!std::memcmp(greedy_original,greedy_message,sizeof greedy_original),"original greedy bytes");
 require(sizeof frame_original==sizeof frame_message&&!std::memcmp(frame_original,frame_message,sizeof frame_original),"original frame bytes");
 require(sizeof transition_original==sizeof transition_message&&!std::memcmp(transition_original,transition_message,sizeof transition_original),"original transition bytes");
 init_slab();
 // 0/1/null/invalid handles, original state word edges and device/list branches.
 for(U op: {4u,5u})for(scene=0;scene<7;++scene)for(U flags: {0u,1u,8u})for(alignment=0;alignment<4;++alignment)for(U value: {0u,1u,0x123456abu,0x80000000u,0xffffffffu}){which=op;variant=flags;level=value;index_bits=5;check();}
 // Compose actual raw 565 setter/wrapper -> raw 568 transition/child and compare
 // to the corresponding compiled bodies. Threshold crossings are signed.
 alignment=0;index_bits=0;for(U op: {1u,3u})for(U scenario: {0u,1u,2u,4u,6u})for(U previous: {0u,2u,0x80000000u})for(U next: {0u,1u,0x7fffffffu})for(U point: {0u,1u,0xffffffffu}){which=op;scene=scenario;variant=0;old_level=previous;level=next;threshold=point;check();}
 variant=0;index_bits=0;alignment=0;old_level=2;level=0;threshold=1;
 pc=2;rc=1;depth=5;sticky=0x25;
 for(U op: {1u,3u,4u,5u})for(U scenario: {0u,1u,2u,4u}){which=op;scene=scenario;check();}
 __asm fninit
 std::printf("audio_greedy_transition_original_x86_vs_cpp=PASS cases=%u events=%u\n",cases,events_total);return 0;
}
