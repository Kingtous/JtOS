#include "jsystem.h"

namespace jsystem
{
    int shutdown_command = LINUX_REBOOT_CMD_RESTART;
} // namespace jsystem


int shutdown(int argc,char* argv[]){
    jsystem::shutdown_command = LINUX_REBOOT_CMD_POWER_OFF;
    return reboot(argc,argv);
}

int restart(int argc,char* argv[]){
    jsystem::shutdown_command = LINUX_REBOOT_CMD_RESTART;
    return reboot(argc,argv);
}

int reboot(int argc,char* argv[]){
    int result_code = -1;
    int reboot_call_serial = 88;

    int magic_1 = LINUX_REBOOT_MAGIC1;
    int magic_2 = LINUX_REBOOT_MAGIC2;

    printf("\n COMMAND: %8p\n",jsystem::shutdown_command);

    asm volatile(
        "movl %1,%%eax \n\t"
        "int $0x80 \n\t"
        "movl %%ebx,%0 \n\t"
        : "=m"(result_code)
        : "r"(reboot_call_serial),"ebx"(magic_1),"ecx"(magic_2),"edx"(jsystem::shutdown_command)
        : "eax","ebx","ecx","edx"
    );
    printf("the result code is %d",&result_code);
    return 0;
}

