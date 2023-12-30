#include "User.h"

void createUserList(ListUser &L) {
    firstUser(L) = nilUser;
}

AddressUser allocateUser(UserInfo x) {
    AddressUser P = new ElementUser;
    infoUser(P) = x;
    nextUser(P) = nilUser;
    prevUser(P) = nilUser;
    return P;
}

void insertLastUser(ListUser &L, AddressUser P) {
    if (firstUser(L) == nilUser) {
        nextUser(P) = P;
        prevUser(P) = P;
        firstUser(L) = P;
    } else {
        nextUser(P) = firstUser(L);
        prevUser(P) = prevUser(firstUser(L));
        nextUser(prevUser(firstUser(L))) = P;
        prevUser(firstUser(L)) = P;
    }
}

AddressUser findUserByUsername(const ListUser &userList, const string &username) {
    AddressUser currentUser = firstUser(userList);

    while (currentUser != nilUser) {
        if (infoUser(currentUser).username == username) {
            return currentUser;  // Found the user
        }
        currentUser = nextUser(currentUser);
    }

    return nilUser;  // User not found
}

bool checkUsername(ListUser L, string name) {
    AddressUser P = firstUser(L);

    if (P == nilUser) {
        return false; // Empty list, username not found
    }

    do {
        if (infoUser(P).username == name) {
            return true; // Username found
        }
        P = nextUser(P);
    } while (P != firstUser(L));

    return false; // Username not found
}

void registerUser(ListUser &L) {
    AddressUser Q;
    UserInfo dataUser;
    string name, pass;

    cout << "\n+=============================+" << endl;
    cout << "|        User Registration     |" << endl;
    cout << "+=============================+" << endl;

    cout << "Username: ";
    cin >> name;

    if (checkUsername(L, name)) {
        cout << "Username already taken" << endl;
        return;
    } else {
        dataUser.username = name;
    }

    cout << "Password: ";
    cin >> pass;

    dataUser.password = pass;
    dataUser.status = false;
    Q = allocateUser(dataUser);
    insertLastUser(L, Q);

    cout << "User successfully registered!" << endl;
    return;
}


bool loginUser(ListUser L, string username, string password) {
    AddressUser P = firstUser(L);

    if (P == nilUser) {
        return false; // Empty list, login failed
    }

    do {
        if (infoUser(P).username == username && infoUser(P).password == password) {
            return true; // Login successful
        }
        P = nextUser(P);
    } while (P != firstUser(L));

    return false; // Login failed
}

void showAllUser(ListUser& L) {
    int i = 1;
    AddressUser P = firstUser(L);

    if (P != nilUser) {
        cout << "\nDaftar User" << endl;
        do {
            cout << "User-" << i << ": " << infoUser(P).username << endl;
            i++;
            P = nextUser(P);
        } while (P != firstUser(L));
    } else {
        cout << "Kosong" << endl;
    }
}
