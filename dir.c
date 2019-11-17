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
int size,fd;
size=0;
struct stat *file=malloc(sizeof(struct stat));
  DIR *d=opendir("../");
    if (d==NULL) printf("Error opening directory. Error #%d\n",errno);
  place=readdir(d);
    if (place==NULL) printf("Error reading directory.\n");
  while (place!=NULL){
    sprintf(info,"../%s",place->d_name);
    int fd= stat(info,file);
  if (place->d_type==4){
    sprintf(info,"%s | Size: %lld\n",place->d_name, file->st_size);
  strcat(directories,info);
  size+=file->st_size;
}
else {
  if (fd <0) printf("Error encountered.\n");
  size+=file->st_size;
    sprintf(info,"%s | Size: %lld\n",place->d_name, file->st_size);
    strcat(regfiles,info);
}
  place=readdir(d);
}
printf("Total directory size: %d Bytes\n",size);
printf("\nDirectories: \n");
printf("%s",directories);
printf("\nRegular files: \n");
printf("%s\n",regfiles);
  return 0;
}
