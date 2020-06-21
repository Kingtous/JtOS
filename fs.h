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
#define OUTPUT_ERROR fprintf(stderr, "%s\n", strerror(errno));

extern int errno;

// get current folder
int Cwd(int argc, char **argv);

// list current dir
int Ls(int argc, char **argv);

// chdir
int Cd(int argc, char **argv);

int Rm(int argc, char **argv);


#endif