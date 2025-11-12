#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "src/theme/theme.h"
#include "src/structs/structs.h"
#include "src/input.h"

#define MAX_SIZE 128

// Retorna: Vetor de Strings, Quantidade de Strings
void promptVectorization(char *input, char ***tokens, char *token, int *n){
    
    (*tokens) = malloc(sizeof(char*));
    token = strtok(input, " ");

    int i = 0;
    
    while(1){
        
        if(token != NULL){
            
            (*n)++;

            (*tokens)[i] = malloc(strlen(token) + 1);
            
            strcpy((*tokens)[i], token);
                
            (*tokens) = realloc((*tokens), sizeof(char*) * (*n));
        
        } else {
            (*n)--;

            break;
        }

        token = strtok(NULL, " ");
        
        i++;
    }
}

int main(){ 

    char input[MAX_SIZE];

    system("clear");

    printf(INPUT " >> ");
    fgets(input, MAX_SIZE, stdin); 
    
    // *token : String
    // **tokens : Vetor de Strings
    char *token;
    char **tokens;

    int numTokens = 1;

    promptVectorization(input, &tokens, token, &numTokens);

    for(int i = 0; i < numTokens; i++){
        printf("\n String: %s", tokens[i]);
    }

    printf(RESET "\n");

    // Liberar Memória
    for(int i = 0; i < numTokens; i++){
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}