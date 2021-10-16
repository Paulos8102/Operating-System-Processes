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
    printf("Leave Space between created file and argument!\n");

  char *file = argv[1];
  printf("Press Enter to create a file");
  getchar(); 

  int f = creat(file,0666);
  printf("\nFile Successfully Created!");
  close(f);     

  printf("Checking user rights\n");
  if (!access(file, R_OK & W_OK & F_OK)) //it checks the file's accessibilty
	  printf("The File can be read!!\n");
  else
  {
    printf("Oops, Permission denied!\n");
    return 0;
  }

  printf("\nEnter any key to check whether the file could be opened or not: ");
  getchar();

  f = open(file, O_RDWR | O_CREAT);
  if (f < 0)
	  printf("Error opening the file\n");
  else
	  printf("File opened successfully\n");
}
