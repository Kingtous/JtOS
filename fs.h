// FileSystem Bundle
// Author: Kingtous
// Description: Support JtOS's File Operations
#ifndef FS_H
#define FS_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "menu.h"

extern int errno;

// get current folder
int cwd(int argc,char* argv[]);

// list current dir
int ls(int argc,char* argv[]);

// chdir
int cd(int argc,char* argv[0]);



#endif