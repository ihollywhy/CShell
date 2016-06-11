#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "myshell.h"

/*
 *============================================================
 *	name: myshell
 *	input: none
 *	output: int
 *	may contains the error code.
 *	version: 1.0
 *	description: print the prompts in command line
 *	it contains the user name, current pass
 *============================================================
 */

int main()
{
    int index;
    int status = 0;
    int myexit = 0;				//flag that indicates user want quit
    
    command = malloc(sizeof(char) * max_command);
    argv = malloc(sizeof(char *) * max_command);

    while(!myexit)				//loop forever unless the myexit is true;
    {
    	PrintPrompt();				//print prompt for user each loop
                GetCommand();
     
        if(strcasecmp(command, "exit") == 0)	//compare the command with "exit"
        {
            return 0;				//set the myexit to true
        }	
        if(strcasecmp(command, "cd") == 0)
        {
                cd();
        }
        else
        {
    	pid_t ischild;
    	ischild = fork();
    	if(ischild != 0)
    	{
            waitpid(ischild, &status, 0);
                    }
                    else
                    {
            	       exec();
                    } 
            }
    }
    return 0;
}


