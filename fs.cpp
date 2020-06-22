#include "fs.h"


int Cwd(int argc, char **argv)
{
	char *dir_name = get_current_dir_name();
	if (dir_name == NULL)
	{
		fprintf(stderr, "%d-error getting current directory name.\n", &errno);
		return -1;
	}
	printf("current dir:%s\n", dir_name);
	return 0;
}



// list
int Ls(int argc, char **argv)
{
	DIR *dir;
	struct dirent *entry;
	struct stat statbuf;
	char *path;
	if (argc != 2)
	{
		if (argc == 1)
		{
			path = ".";
		}
		else
		{
			fprintf(stderr, "Usage: Ls <path>\n", errno);
			return 0;
		}
	}
	else
	{
		path = argv[1];
	}
	// open dir
	printf("opening: %s\n", path);
	if ((dir = opendir(path)) == NULL)
	{
        OUTPUT_ERROR;
        return errno;
    }
	else
	{
		// read files info
		printf("%s \t %s \t %s \n","TYPE","NAME","SIZE(KB)");
		while ((entry = readdir(dir)) != NULL)
		{
			lstat(entry->d_name, &statbuf);
			if (S_ISDIR(statbuf.st_mode))
			{
				// if is . and .., then skip
				if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
				{
					continue;
				}
				printf("%s \t %s \t %ldKB\n", "DIR", entry->d_name,statbuf.st_size/1024);
			}
			else
			{
				printf("%s \t %s \t %ldKB\n", "FILE", entry->d_name,statbuf.st_size/1024);
			}
		}
		// output
		closedir(dir);
		return 0;
	}
}

// chdir
int Cd(int argc, char **argv){
	if (argc == 1)
	{
		return 0;
	}
	else if (argc > 2)
	{
		fprintf(stderr,"Usage: Cd <dir>\n");
	}
	else
	{
		int code = chdir(argv[1]);
		if (code != 0)
		{
			fprintf(stderr,"%s\n",strerror(errno));
			return code;
		}
		else
		{
			char* current_dir_name = get_current_dir_name();
			char* prompt_header = strcat(current_dir_name," >> ");
			SetPrompt(prompt_header);
		}
	}
	return 0;
}
void DeleteFile(const char* path);

int Rm(int argc, char **argv) {
    if (argc == 1)
    {
        return 0;
    } else if (argc > 2) {
        fprintf(stderr, "Usage: Rm <dir/file>\n");
    } else {
        DeleteFile(argv[1]);
        return 0;
    }
}

static bool touch(const char *file);

int Touch(int argc, char **argv) {
    if (argc == 1) {
        return 0;
    } else if (argc > 2) {
        fprintf(stderr, "Usage: touch <file>\n");
    } else {
        touch(argv[1]);
        return 0;
    }
}

static bool touch(const char *file) {
    bool ok;
    int fd = -1;
    if (!no_create) {
        fd = open(file, O_CREAT | O_WRONLY, MODE_RW_UGO);
    }
    newtime[0].tv_nsec = UTIME_NOW;
    newtime[1].tv_nsec = UTIME_NOW;
    //AT_FDCWD表示当前工作目录。
    ok = (utimensat(AT_FDCWD, file, newtime, 0) == 0);
    return ok;
}

int Mkdir(int argc, char **argv) {
    if (argc == 1) {
        return 0;
    } else if (argc > 2) {
        fprintf(stderr, "Usage: touch <file>\n");
    } else {
        if (mkdir(argv[1], 0755) != 0) {
            OUTPUT_ERROR;
        }
        return 0;
    }
    return 0;
}

int Edit(int argc, char **argv) {

    return 0;
}

void AppendPath(const char *path, const char *filename, char *filepath) {
    strcpy(filepath, path);
    if (filepath[strlen(path) - 1] != '/')
        strcat(filepath, "/");
    strcat(filepath, filename);
}

void DeleteFile(const char *path)
{
    DIR *dir;
    struct dirent *dirinfo;
    struct stat statbuf;
    char filepath[256] = {0};
    lstat(path, &statbuf);
    if (S_ISREG(statbuf.st_mode))//判断是否是常规文件
    {
        if (remove(path) != 0) {
            OUTPUT_ERROR;
        }
    }
    else if (S_ISDIR(statbuf.st_mode))//判断是否是目录
    {
        if ((dir = opendir(path)) == NULL)
            return;
        while ((dirinfo = readdir(dir)) != NULL) {
            AppendPath(path, dirinfo->d_name, filepath);
            if (strcmp(dirinfo->d_name, ".") == 0 || strcmp(dirinfo->d_name, "..") == 0)//判断是否是特殊目录
                continue;
            DeleteFile(filepath);
            rmdir(filepath);
        }
        closedir(dir);
    }
}
