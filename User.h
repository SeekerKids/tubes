#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <iostream>
#include <string>

#define firstUser(L) L.firstUser
#define nextUser(P) P->nextUser
#define prevUser(P) P->prevUser
#define infoUser(P) P->infoUser
#define nilUser NULL
#include "BankSoal.h"


using namespace std;

struct User {
    string username;
    string password;
    bool status;
    int skor;
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
void deleteLastUser(ListUser &L, AddressUser &P);
bool checkUsername(ListUser L, string name);
void registerUser(ListUser &L);
bool loginUser(ListUser L, string username, string password);
void showAllUser(ListUser& L);
void displayParticipantScores(ListUser L);
int countUser(ListUser L);
void SortDescending(ListUser L);
void Quiz(ListUser &LU, ListSoal &LS);
#endif // USER_H_INCLUDED
