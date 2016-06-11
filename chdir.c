#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myshell.h"
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int max_length;
	char * current_path;
	current_path  = malloc(sizeof(char) * max_length);
	getcwd(current_path, max_length);
	printf("current_path:%s\n", current_path);
	if(chdir("/home") ==  0)
		printf("OK\n");
	getcwd(current_path, max_length);
	printf("change_path:%s\n", current_path);
	return 0;
}