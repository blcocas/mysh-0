#include <stdlib.h>
#include "utils.h"
#include <string.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	char *command_copy;//to get command
	char *token;//token
	*argc = 0;

	command_copy = (char*)calloc(strlen(command),sizeof(char*));
	strcpy(command_copy,command);
	
	token = strtok(command_copy, " \t\n");
	*argv = (char**)calloc(sizeof(char*),1);

	if (token == NULL){ //first token
		*argv[0] = (char*)calloc(sizeof(char),1);
		strcpy((*argv)[0],"");
		*argc = 1;
		return;
	}
	else {
	
		*argv[0] = (char*)calloc(sizeof(char),strlen(token));
		strcpy((*argv)[0], token);
	}

	while (token = strtok(NULL, " \t\n")) {//next and next ~ token
		(*argc)++;
		*argv = (char**)realloc(*argv,sizeof(char*)*(*argc + 1));
		(*argv)[*argc] = (char*)calloc(sizeof(char), strlen(token));
		strcpy((*argv)[*argc],token);
	}
	
	(*argc)++;
	free(command_copy);
	return;
}
