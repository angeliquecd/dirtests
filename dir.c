#include<stdlib.h>
#include <sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<dirent.h>
int main(){
char info[100];
struct dirent *place= malloc(sizeof(struct dirent));
int size,fd;
size=0;
struct stat *file=malloc(sizeof(struct stat));
  DIR *d=opendir("../");
  if (d==NULL) printf("Error opening directory. Error #%d\n",errno);
  place=readdir(d);
  if (place==NULL) printf("Error reading directory.\n");
  while (place!=NULL){
    //fd = open(place->d_name,O_RDONLY);
    //result-read(fd,buff,sizeof(buff));
    sprintf(info,"../%s",place->d_name);
    int fd= stat(info,file);
  if (place->d_type==4){
  printf("%s | Directory: True | Size: %lld\n",place->d_name,file->st_size);
  size+=file->st_size;
}
else {
  if (fd <0) printf("Error encountered.\n");
  size+=file->st_size;
    printf("%s | Directory: False | Size: %lld\n",place->d_name,file->st_size);
}
  place=readdir(d);
}
printf("Total size: %d\n",size);
  return 0;
}
