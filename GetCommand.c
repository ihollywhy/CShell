#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myshell.h"

/*
 *============================================================
 *	name: PrintPrompt
 *	input: none
 *	output: int
 *	may contains the error code.
 *	version: 1.0
 *	description: print the prompts in command line
 *	it contains the user name, current pass
 *============================================================
 */

#define max_input 1000 		//the max char number of input
#define MAXARG 10

int GetCommand()
{
	char inputs[max_input];
	char *token;
	int index = 0;
	fgets(inputs, max_input, stdin);
	//printf("%s", inputs);

	if(inputs[0] == '\n')
	{
		*command = '\n';
	}
	else
	{
		token = strtok(inputs, " \n");
		argv[0] = token;
		while((token = strtok(NULL, " \n")))
		{
			index++;
			argv[index] = token;
		//	printf("%s", token);
		}
		argv[index+1] = '\0';
	
    		command = argv[0];
	}
	return index;
}
