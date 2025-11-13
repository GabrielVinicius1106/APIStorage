#include <stdio.h>
#include <string.h>
#include "input.h"

int getRoute(char *token){
    if(strcmp(token, "add\n") == 0 || strcmp(token, "add") == 0) return 1;

    if(strcmp(token, "delete\n") == 0 || strcmp(token, "delete") == 0) return 2; 

    if(strcmp(token, "edit\n") == 0 || strcmp(token, "edit") == 0) return 3; 

    if(strcmp(token, "list\n") == 0 || strcmp(token, "list") == 0) return 4; 

    if(strcmp(token, "help\n") == 0) return 5;
}