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
	
	//message printing on the display
	printf("Enter text to write in the file:\n");
	//read from keyboard, specifying 0 as fd for std input device
	//Here, n stores the number of characters	
	n= read(0, buff, 50);

	// creating a new file using open.
	fd=open(filename,O_CREAT | O_RDWR, 0777); 
	
	//writting input data to file (fd)
	write(fd, buff, n);

	printf("\nFile's data:\n");
	//Write to display (1 is standard fd for output device)
	write(1, buff, n);

	//closing the file
	close(fd);
	
	return 0;	
}
