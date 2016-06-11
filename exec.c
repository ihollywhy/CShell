#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myshell.h"
#include <unistd.h>

//For interest cd func
void cd(void)
{
	getcwd(path, sizeof(path));
	strcat(path, "/");
	strcat(path, argv[1]);
	if(chdir(path) ==  0)
		perror("chdir");
}

void exec(void)
{
	if(*command == '\n')
	{
		exit(0);
	}
       	else 
	{		
		if(!strcasecmp(command, "cd"))
		{
			printf("cd command\n");
			cd();
		}		
		else 
		{
			if(execvp(command, argv) == -1 )
				printf("%s: COMMAND NOT FOUND!\n", command);
			exit(0);
		}
		//exit(0);
	}	
}
