#include <iostream>
#include "file_system.h"
#include "menu.h"
#include "fs.h"
#include "jtime.h"
#include "jsystem.h"

using namespace std;

#define FONTSIZE 10
#define AUTHOR "Kingtous"
#define PROJECT_DATE "2020-05-23"

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
    printf("Author:%s\nProject Date:%s\n",AUTHOR,PROJECT_DATE);
    return 0;
}

int Version(int argc,char* argv[]){
    printf("JtOS Version 1.0\n");
}

int main(){
    // 文件系统
    sleep(2);
    FileSystem fileSystem(1024);
    PrintOS();
    SetPrompt("/ >> ");
    MenuConfig("version","JtOS V1.0",Version);
    MenuConfig("time","Current Time is",Time);

    MenuConfig("shutdown","shutdown your computer",shutdown);
    MenuConfig("reboot","reboot your computer",restart);
    MenuConfig("pwd","show your current directory",cwd);
    MenuConfig("ls","list files from directory",ls);
    MenuConfig("cd","change to a new directory",cd);
    ExecuteMenu();

    return 0;
}