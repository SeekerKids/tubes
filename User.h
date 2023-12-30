#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <iostream>
#include <string>

#define firstUser(L) L.firstUser
#define nextUser(P) P->nextUser
#define prevUser(P) P->prevUser
#define infoUser(P) P->infoUser
#define nilUser NULL

using namespace std;

struct User {
    string username;
    string password;
    bool status;
};

typedef struct ElementUser *AddressUser;
typedef User UserInfo;

struct ElementUser {
    UserInfo infoUser;
    AddressUser nextUser;
    AddressUser prevUser;
};

struct ListUser {
    AddressUser firstUser;
};

void createUserList(ListUser &L);

AddressUser allocateUser(UserInfo x);

void insertLastUser(ListUser &L, AddressUser P);

AddressUser findUserByUsername(const ListUser &userList, const string &username);

bool checkUsername(ListUser L, string name);

void registerUser(ListUser &L);

bool loginUser(ListUser L, string username, string password);

void showAllUser(ListUser& L);

#endif // USER_H_INCLUDED
