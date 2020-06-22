#ifndef JTIME
#define JTIME

#include <cstdio>
#include <ctime>
#include <sys/sem.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/ioctl.h>
#include <termio.h>
#include "file_system.h"

#define LOCK_SCREEN_TIME 30

// time pass mutex
extern pthread_mutex_t time_pass_lock;
// +1 one second
extern unsigned int time_pass;
// lockscreen thread symbol
extern pthread_t lockscreen_pth;


int clearScreen(int argc, char *argv[]);

// get time
int Time(int argc, char *argv[]);

int RowColumnValue(int argc, char *argv[]);

int InitTimeScreen();

#endif