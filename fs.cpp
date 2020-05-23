#include "fs.h"

int cwd(int argc,char* argv[]){
	char * dir_name = get_current_dir_name();
	if (dir_name == NULL){
		fprintf(stderr,"%d-error getting current directory name.\n",&errno);
		return -1;
	}
	printf("current dir:%s\n",dir_name);
	return 0;
}

// list 
int ls(int argc,char* argv[]){
	DIR *dir;
	struct dirent *entry;
	struct stat statbuf;
	if(argc != 2){
		fprintf(stderr,"Please Input A Valid Directory Name.\n",errno);
		return 0;
	}
	// open dir
	printf("opening: %s\n",argv[1]);
	if ((dir = opendir(argv[1])) == NULL){
		fprintf(stderr,"%s\n",strerror(errno));
		return errno;
	} else {
		// read files info
		while((entry = readdir(dir)) != NULL){
			lstat(entry->d_name,&statbuf);
			if (S_ISDIR(statbuf.st_mode)) {
				// if is . and .., then skip
				if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0 ){
					continue;
				}
				printf("%s \t %s\n","DIR", entry->d_name);
			} else{
				printf("%s \t %s\n","FILE", entry->d_name);
			}
		}
		// output
		closedir(dir);
		return 0;
	}
}