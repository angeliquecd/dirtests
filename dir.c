#include<stdlib.h>
#include <sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<dirent.h>
int main(){
struct dirent *place= malloc(sizeof(struct dirent));
int size,fd;
char buff[100];
  DIR *d=opendir("../");
  if (d==NULL) printf("Error opening directory. Error #%d\n",errno);
  place=readdir(d);
  if (place==NULL) printf("Error reading directory.\n");
  while (place!=NULL){
    fd = open(place->d_name,O_RDONLY);
    result-read(fd,buff,sizeof(buff));
  if (place->d_type==4){
  printf("%s | Directory: True\n",place->d_name);
  size+=4096;
}
else {
    printf("%s | Directory: False\n",place->d_name);
    size+=
}
  place=readdir(d);}
printf("Total size: %d",size);
  return 0;
}