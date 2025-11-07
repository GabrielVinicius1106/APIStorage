#ifndef STRUCTS_H
#define STRUCTS_H

struct API_Key{
    int id;
    int user_id;
    char *service;
    char *name;
    char *key;
    char *until;
};

struct User{
    int id;
    char *login;
    char *password;
};

int getApiKeyID(struct API_Key api_key);

int getUserID(struct User user);



#endif