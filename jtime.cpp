#include "jtime.h"

// time pass mutex
pthread_mutex_t time_pass_lock = PTHREAD_MUTEX_INITIALIZER;
// +1 one second
unsigned int time_pass = 0;
// lockscreen thread symbol
pthread_t lockscreen_pth = 0;

int Time(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("argv-%d: %s\n", i, argv[i]);
    }

    time_t tt;
    struct tm *t;
    tt = time(NULL);
    t = localtime(&tt);
    printf("time:%d:%d:%d:%d:%d:%d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    return 0;
}

static void startScreenCount();

int InitTimeScreen() {
    // init mutex
//    lockscreen_pth = 0;
//    time_pass_lock = PTHREAD_MUTEX_INITIALIZER;
    // call screen count
    pthread_create(&lockscreen_pth, NULL, reinterpret_cast<void *(*)(void *)>(startScreenCount), NULL);
    return 0;
}

int RowColumnValue(int argc, char **argv) {
    struct winsize wsize{};
    ioctl(STDIN_FILENO, TIOCGWINSZ, &wsize);
    printf("Row: %d\tCol: %d\n", wsize.ws_row, wsize.ws_col);
//    printf("X Pixel: %d\tY Pixel: %d\n",wsize.ws_xpixel,wsize.ws_ypixel);
    return 0;
}

// should only executed in subprocess
static void startScreenCount() {
    time_pass = 0;
    while (1) {
        sleep(1);
        pthread_mutex_lock(&time_pass_lock);
        //printf("current time_pass:%d\n",time_pass);
        if (time_pass >= LOCK_SCREEN_TIME) {
            // get current time
            time_t tt;
            struct tm *t;
            tt = time(NULL);
            t = localtime(&tt);
            t->tm_year += 1900;
            // get pixels location
            struct winsize wsize;
            ioctl(STDIN_FILENO, TIOCGWINSZ, &wsize);
            // show lock screen
            clearScreen(NULL, NULL);
            //
            PrintOS();
            printf("\033[%d;%dH", wsize.ws_row / 2 + 5, wsize.ws_col / 2 - 15); // y,x
            printf("current time:%d-%02d-%02d %02d:%02d:%02d\n", t->tm_year, t->tm_mon + 1, t->tm_mday, t->tm_hour + 8,
                   t->tm_min, t->tm_sec);
        } else {
            time_pass += 1;
        }
        pthread_mutex_unlock(&time_pass_lock);
    }
}

int clearScreen(int argc, char *argv[]) {
    printf("\x1b[H\x1b[2J");
    return 0;
}
