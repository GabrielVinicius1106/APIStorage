#include <stdlib.h>
#include <string.h>
#include "validateInput.h"

int validateInput(char *input){
    if(strcmp(input, "add") == 0) return 1;

    if(strcmp(input, "del") == 0) return 2; 

    if(strcmp(input, "edit") == 0) return 3; 

    if(strcmp(input, "list") == 0) return 4; 

    if(strcmp(input, "help") == 0) return 5;
}