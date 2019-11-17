#include<stdlib.h>
#include <sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<dirent.h>
#include<string.h>
int main(){
char info[100];
char *directories=malloc(1000000000);
char *regfiles=malloc(10000000000);
struct dirent *place= malloc(sizeof(struct dirent));
int size,fd,regsize;
size=0;
regsize=0;
struct stat *file=malloc(sizeof(struct stat));


DIR *d=opendir(".");
    if (d==NULL) printf("Error opening directory. Error #%d\n",errno);
place=readdir(d);
    if (place==NULL) printf("Error reading directory.\n");

while (place!=NULL){
  //  printf("%s\n",place->d_name);
    int fd= stat(place->d_name,file);
      if (fd <0) printf("Error encountered. %d\n",errno);
  if (place->d_type==4){
    sprintf(info,"%s | Size: %lld\n",place->d_name, file->st_size);
  strcat(directories,info);
  size+=file->st_size;
}
else {
  size+=file->st_size;
  regsize+=file->st_size;
    sprintf(info,"%s | Size: %lld\n",place->d_name, file->st_size);
    strcat(regfiles,info);
}
  place=readdir(d);
}

printf("Total size of directory: %d Bytes\n",size);
printf("\nDirectories: \n");
printf("%s",directories);
printf("\nTotal size of regular files: %d Bytes\n",regsize);
printf("Regular files: \n");
printf("%s\n",regfiles);
  return 0;
}
