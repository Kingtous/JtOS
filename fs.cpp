#include "fs.h"


int cwd(int argc, char *argv[])
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
int ls(int argc, char *argv[])
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
			fprintf(stderr, "Usage: ls <path>\n", errno);
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
		fprintf(stderr, "%s\n", strerror(errno));
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
int cd(int argc,char* argv[]){
	if (argc == 1)
	{
		return 0;
	}
	else if (argc > 2)
	{
		fprintf(stderr,"Usage: cd <dir>\n");
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