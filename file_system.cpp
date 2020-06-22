#include <iostream>
#include "file_system.h"
#include "menu.h"
#include "fs.h"
#include "jtime.h"
#include "jsystem.h"

using namespace std;

#define FONTSIZE 10
#define AUTHOR "Kingtous"
#define PROJECT_DATE "2020-05-23~today"

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
        usleep(50000);
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_T[i][j]);
        }
        usleep(50000);
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_O[i][j]);
        }
        usleep(50000);
        for(j=0; j<FONTSIZE; j++)
        {
            printf("%c", data_S[i][j]);
        }
        printf("\n");
    }
    printf("Author:%s\nProject Date:%s\n",AUTHOR,PROJECT_DATE);
    return 0;
}

int Version(int argc,char* argv[]){
    printf("JtOS Version 1.0\n");
    return 0;
}

int main(){
    // 文件系统
    sleep(2);
    FileSystem fileSystem(1024);
    PrintOS();
    SetPrompt("/ >> ");
    MenuConfig("version", "JtOS V1.0", Version);
    MenuConfig("time", "Current Time is", Time);
    MenuConfig("Shutdown", "Shutdown your computer", Shutdown);
    MenuConfig("reboot", "reboot your computer", Restart);
    MenuConfig("pwd", "show your current directory", Cwd);
    MenuConfig("ls", "list files from directory", Ls);
    MenuConfig("cd", "change to a new directory", Cd);
    MenuConfig("rm", "remove file/dir", Rm);
    MenuConfig("touch", "create empty file", Touch);
    MenuConfig("mkdir", "create empty directory", Mkdir);
    MenuConfig("edit", "edit file", Edit);
    MenuConfig("rc", "get row and column size", RowColumnValue);
    MenuConfig("cls", "clear screen", clearScreen);
    // 初始化时间Screen
    InitTimeScreen();
    ExecuteMenu();
    return 0;
}