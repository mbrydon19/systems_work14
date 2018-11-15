#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

char ** parse_args(char * line) {
  char * str1 = line;
  char * str2 = "";
  char ** arg_arr = (char **) malloc( 100);
  int index = 0;
  while ( str2) {
    str2 = strsep( &str1, " ");
    arg_arr[index] = str2;
    index++;
  }
  arg_arr[index] = NULL;
  return arg_arr;
} 

int main() {
  char * line = (char *) malloc( 256);
  strcpy( line, "ls -l");
  char ** args = parse_args(line);
  execvp(args[0], args);
    
  return 0;
}
