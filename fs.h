// FileSystem Bundle
// Author: Kingtous
// Description: Support JtOS's File Operations
#ifndef FS_H
#define FS_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <cstdio>
#include <cerrno>
#include <cstring>
#include <getopt.h>
#include <sys/types.h>
#include <ctime>
#include <fcntl.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <sys/stat.h>

#define CH_ATIME 1
#define CH_MTIME 2

#include "menu.h"
#include "sys/stat.h"

#define OUTPUT_ERROR fprintf(stderr, "\n%s\n", strerror(errno))

//定义创建文件时的模式，此处对用户，组，其他设置的权限都是可读可写。
#define MODE_RW_UGO (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

// should be called first
int initFs();

//标志文件access time 和 modify time的改变情况
static int change_times;

// 如果有(-c)选项，并且不存在命令行中输入的文件名，则不创建
static bool no_create;

//当设置新的access time 和 modify time的时候使用
static struct timespec newtime[2];

extern int errno;

// get current folder
int Cwd(int argc, char **argv);

// list current dir
int Ls(int argc, char **argv);

// chdir
int Cd(int argc, char **argv);

int Rm(int argc, char **argv);

int Touch(int argc, char **argv);

int Mkdir(int argc, char **argv);

int Edit(int argc, char **argv);


#endif