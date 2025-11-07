#include <stdio.h>
#include "style/theme.h"
#include "src/structs.h"

int main(){ 

    struct User user;

    user.id = 1;
    user.login = "gabriel";
    user.password = "12345";

    struct API_Key api_key;

    api_key.id = 2;
    api_key.user_id = 1;
    api_key.key = "abc123";
    api_key.name = "Minha Chave de API";
    api_key.service = "Gemini";
    api_key.until = "07/11/2026";

    printf("User ID: %d\n", getUserID(user));
    printf("User Login: %s\n", user.login);
    printf("User Password: %s\n\n", user.password);
    
    printf("API_Key ID: %d \n", getApiKeyID(api_key));
    printf("API_Key UserID: %d\n", api_key.user_id);
    printf("API_Key Service: %s\n", api_key.service);
    printf("API_Key Key: %s\n", api_key.key);
    printf("API_Key Name: %s\n", api_key.name);
    printf("API_Key Until: %s\n\n", api_key.until);



    return 0;
}