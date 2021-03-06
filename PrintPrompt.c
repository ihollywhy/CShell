#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
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
int PrintPrompt()
{
	struct passwd *user_info;          	//define a struct to save the user info
	int maxlen = 50;			//define the user_info's max length
	char hostname[maxlen];
	char pwds[maxlen];			//define a char string

	user_info = getpwuid(getuid());    		//get the user info
	gethostname(hostname, sizeof(hostname));  	//get the hostname
//	getcwd(pwds, sizeof(pwds));			//get the pwd, ~ means the home path
	getcwd(path, sizeof(path));			//get the pwd, ~ means the home path


	printf("%s@%s:%s$", user_info->pw_name, hostname, path);

	return 0;
}
