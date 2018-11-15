#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args(char * line) {
    char * str1 = line;
    char * str2 = "";
    char * arg_arr[100];
    int index = 0;
    while ( str2) {
        str2 = strsep(&str1, " ");
        arg_arr[index] = str2;
        index++;
    }
    arg_arr[index] = NULL;
    return arg_arr;
} 

int main() {
    char * line = "ls -l";
    char ** args = parse_args(line);
    execvp(args[0], args);
    
    return 0;
}
