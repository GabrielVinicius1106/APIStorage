#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "src/theme/theme.h"
#include "src/structs/structs.h"
#include "src/input.h"

int main(){ 

    char *input;

    system("clear");

    printf(INPUT " >> ");
    // scanf("%s", input);
    readInput(input);
    

    return 0;

    int option = validateInput(input); 

    switch(option){
    case 1:
        // ADD
        printf("Adicionar Chave! \n");
        break;

    case 2:
        // DEL
        printf("Deletar Chave! \n");
        break;

    case 3:
        // EDIT
        printf("Editar Chave! \n");
        break;
        
    case 4:
        // LIST
        printf("Listar Chaves! \n");
        break;
    
    case 5:
        // HELP
        printf("Ajuda! \n");
        break;
    
    default:
        // DEFAULT
        printf("Comando Invalido! \n"); 
        break;
    }
    

    printf(RESET "\n");


    return 0;
}