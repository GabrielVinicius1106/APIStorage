#include <stdio.h>
#include "structs.h"

int getUserID(struct User user){
    return user.id;
};

int getApiKeyID(struct API_Key api_key){
    return api_key.id;
};