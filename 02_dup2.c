#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main ( void )
{

  int output_fds;
  
  output_fds = open ("./output.txt" , O_WRONLY | O_CREAT , S_IRUSR | S_IWUSR );
  dup2 (output_fds, STDOUT_FILENO );
  printf ("coucou bande de bitch!!!\n");
 
  return EXIT_SUCCESS ;

}