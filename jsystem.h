#ifndef J_SYSTEM
#define J_SYSTEM
#include <stdio.h>
#include </usr/include/linux/reboot.h>
#include </usr/include/linux/unistd.h>

int shutdown(int argc,char* argv[]);

int restart(int argc,char* argv[]);

// shall not to directly call rebooot, call functions above.
int reboot(int argc,char* argv[]);

#endif