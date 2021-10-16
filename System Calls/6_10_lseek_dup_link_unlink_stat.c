#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
int main(int argc, char **argv)
{
	int n,fd;
  	char *filename = argv[1];
	char buff[50];	// declaring buffer 

	printf("Enter text to write in the file:\n");
	n = read(0, buff, 50);

	fd = open(filename,O_CREAT | O_RDWR, 0777); 
	
	write(fd, buff, n);

 	 printf("\nFile's data:\n");
	write(1, buff, n);

  lseek(fd, 0, SEEK_SET);
  getchar();
  
  printf("Creating sym link\n");
  char sym_path[50] = "./sym_link/";
  mkdir(sym_path, 0777);
  link(filename, strcat(sym_path, filename));
  printf("Press Enter to get the status");
  getchar();
 
  struct stat s;
  stat(filename, &s);
  printf("File Size	: %ld bytes\n", s.st_size);
  printf("Number of Links : %ld\n", s.st_nlink);
  printf("\nPress enter to unlink the system path");
  getchar();
      
  unlink(sym_path);
  printf("After Unlinking\n");
  stat(filename, &s);
  printf("File Size	: %ld bytes\n", s.st_size);
  printf("Number of Links : %ld\n", s.st_nlink);

  printf("\nPress enter to create the duplicate");
  getchar();
        
  int file_dup = dup(fd);  //creates a duplicate of the file system
  printf("The duplicate is %d\n",file_dup);

  return 0;	
}
