#include <unistd.h>
#include <stdio.h>
int main() 
{
 char buf[1000];
  
 printf("Executing ls command\n");
 FILE *lsp = popen("/bin/ls", "r");
  
 printf("Executing less command\n");
 FILE *lessp = popen("/bin/less", "w");
  
 if(lsp == NULL || lessp == NULL) 
 {
  printf("Failed to run command\n");
  return 1;
 }
 while(fgets(buf, 1000, lsp)) {
 fputs(buf, lessp);
 }
 pclose(lsp);
 pclose(lessp);
}
