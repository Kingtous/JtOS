#include <iostream>
#include "file_system.h"
#include "menu.h"

using namespace std;

#define FONTSIZE 10

int PrintOS()
{
    int i, j;
    char data_J[FONTSIZE][FONTSIZE] =
    {
        "         ",
        "   ***** ",
        "     *   ",
        "     *   ",
        "     *   ",
        "     *   ",
        "     *   ",
        "  *  *   ",
        "   **    ",
        "         "
    };
    char data_T[FONTSIZE][FONTSIZE] =
    {
        "         ",
        " ******* ",
        "    *    ",
        "    *    ",
        "    *    ",
        "    *    ",
        "    *    ",
        "    *    ",
        "         ",
        "         "
    };
    char data_O[FONTSIZE][FONTSIZE] =
    {
        "         ",
        "  ****   ",
        " *    *  ",
        "*      * ",
        "*      * ",
        "*      * ",
        "*      * ",
        " *    *  ",
        "  ****   ",
        "         "
    };
    char data_S[FONTSIZE][FONTSIZE] =
    {
        "         ",
        "   ****  ",
        "  **     ",
        " **      ",
        "  ***    ",
        "    **   ",
        "     **  ",
        "    **   ",
        " ****    ",
        "         "
    };

    for(i=0; i<FONTSIZE; i++)
    {
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_J[i][j]);
        }
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_T[i][j]);
        }
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_O[i][j]);
        }
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_S[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int Quit(int argc, char *argv[])
{
    system("poweroff");
}

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

int Version(int argc,char* argv[]){
    printf("JtOS ");
}

int Shutdown(int argc,char* argv[]){

    int result_code = -1;
    int shutdown_code = 88;

    int magic_1 = LINUX_REBOOT_MAGIC1;
    int magic_2 = LINUX_REBOOT_MAGIC2;

    int shutdown_command = LINUX_REBOOT_CMD_POWER_OFF;

    asm volatile(
        "movl %1,%%eax \n\t"
        "int $0x80 \n\t"
        "movl %%ebx,%0 \n\t"
        : "=m"(result_code)
        : "r"(shutdown_code),"ebx"(magic_1),"ecx"(magic_2),"edx"(shutdown_command)
        : "eax"
    );
    printf("the result code is %d",&result_code);
}

int main(){
    // 文件系统
    FileSystem fileSystem(1024);
    PrintOS();
    SetPrompt("JtOS CS170217 >> ");
    MenuConfig("version","JtOS V1.0",Version);
    MenuConfig("quit","Quit from MenuOS",Quit);
    MenuConfig("time","Current Time is",Time);
    MenuConfig("shutdown","shutdown your computer",Shutdown);
    ExecuteMenu();

    // while (true){
    //     printf("FileSystem: %s > ",fileSystem.getCurrentFolder().c_str());
    //     cin>>op>>value;
    //     if(op == "format"){
    //         fileSystem.format();
    //     }
    //     else if(op == "rm"){
    //         fileSystem.rm(value);
    //     }
    //     else if(op == "create"){
    //         int length;
    //         printf("File Length:");
    //         cin>>length;
    //         fileSystem.create(value,length);
    //     }
    //     else if(op == "write"){
    //         printf("Input Content:");
    //         cin>>extra;
    //         fileSystem.write(value,extra);
    //     }
    //     else if(op == "read"){
    //         fileSystem.read(value);
    //     }
    //     else if(op =="open"){
    //         fileSystem.open(value);
    //     }
    //     else if(op == "close"){
    //         fileSystem.close(value);
    //     }
    //     else if(op == "ls"){
    //         fileSystem.ls();
    //     }
    //     else if(op =="mkdir"){
    //         fileSystem.mkdir(value);
    //     }
    //     else if(op == "rmdir"){
    //         fileSystem.rmdir(value);
    //     }
    //     else if(op == "cd"){
    //         fileSystem.cd(value);
    //     }
    //     else if(op == "exit"){
    //         break;
    //     }
    //     else{
    //         fprintf(stderr,"\nUnknown Operator.\n");
    //     }
    //     cout<<endl;
    // }
    return 0;
}