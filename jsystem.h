#ifndef J_SYSTEM
#define J_SYSTEM
#include <cstdio>
#include </usr/include/linux/reboot.h>
#include </usr/include/linux/unistd.h>

int Shutdown(int argc, char **argv);

int Restart(int argc, char **argv);

// shall not to directly call rebooot, call functions above.
int reboot(int argc,char* argv[]);

#endif