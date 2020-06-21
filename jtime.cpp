#include "jtime.h"

int Time(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("argv-%d: %s\n",i,argv[i]);
    }
    
    time_t tt;
    struct tm *t;
    tt = time(NULL);
    t = localtime(&tt);
    printf("time:%d:%d:%d:%d:%d:%d\n",t->tm_year+1900, t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    return 0;
}

int InitTimeScreen() {
    return 0;
}
