#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
 if(argc<2) 
  printf("You have to enter the file name alone with the file to be created");
  
 char *filename = argv[1];
 printf("Press Enter to create a file");
 getchar(); 
  
 int f = creat(filename,0666);
 
 printf("\n\nFile Successfully Created!\n");
 close(f); 
}
