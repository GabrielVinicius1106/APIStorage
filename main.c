#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "src/date/date.h"
#include "src/input.h"
#include "src/structs/structs.h"
#include "src/theme/theme.h"

#define MAX_SIZE 128

// Vetoriza a String de Comando, e retorna o número de Tokens
void promptVectorization(char *input, char ***tokens, int *n){
    
    (*tokens) = malloc(sizeof(char*));
    char *token = strtok(input, " ");

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

// Libera a Memória Utilizada
void freeMemory(char ***tokens, int numTokens){
    for(int i = 0; i < numTokens; i++){
        free((*tokens)[i]);
    }
    free(*(tokens));
}

// Cria uma Nova Chave de API
void createAPIKey(struct API_Key *apiKeys, char *service, char *api_key, char *name, char *until, int numAPIKeys){

    apiKeys = realloc(apiKeys, sizeof(struct API_Key) * numAPIKeys);

    strcpy(apiKeys->service, service);
    strcpy(apiKeys->key, api_key);
    strcpy(apiKeys->name, name);
    // strcpy(apiKeys->until, until);
}

int main(){ 

    char input[MAX_SIZE];

    int numKeys = 0;

    system("clear");

    printf(INPUT " >> ");
    fgets(input, MAX_SIZE, stdin); 

    char **tokens;
    int numTokens = 1;

    promptVectorization(input, &tokens, &numTokens);
    
    int route = getRoute(tokens[0]);

    printf(OUTPUT);

    for(int i = 0; i < numTokens; i++){
        printf("\n token[%d] : %s", i, tokens[i]);
    }

    struct API_Key newApiKey;

    switch(route){

        case 1:
            // POST
            // createAPIKey();

            numKeys++;

            if(tokens[1] != NULL){
                strcpy(newApiKey.service, tokens[1]);
            }

            if(tokens[2] != NULL){
                strcpy(newApiKey.key, tokens[2]);
            }

            if(tokens[3] != NULL){
                strcpy(newApiKey.name, tokens[3]);
            }

            // createAPIKey(apiKeys ,service, api_key, name, until, 1);

            break;

        case 2:
            // DELETE
            break;


        case 3:
            // EDIT
            break;


        case 4:
            // GET
            break;

        case 5: 
            // HELP
            break;

        default:
            break;
    }
    
    printf("\n Option: %d", route);
    printf("\n Numero de Tokens: %d \n", numTokens);

    printf("\n Serviço: %s", newApiKey.service);
    printf("\n Chave de API: %s", newApiKey.key);
    printf("\n Nome: %s", newApiKey.name);

    printf(RESET "\n");

    freeMemory(&tokens, numTokens);

    return 0;
}