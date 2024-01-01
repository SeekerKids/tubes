#include "User.h"
#include "BankSoal.h"


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
void deleteLastUser(ListUser &L, AddressUser &P){
    AddressUser Q;
    if (firstUser(L) == nullptr) {
        cout << "List Kosong " << endl;
    } else if (nextUser(firstUser(L)) == nullptr) {
        P = firstUser(L);
        firstUser(L) = nullptr;
    } else{
        P = firstUser(L);
        do {
            Q = P;
            P = nextUser(P);
        } while (nextUser(P) != firstUser(L));
        nextUser(Q) = nullptr;
    }
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
            cout << infoUser(P).skor << endl;
            P = nextUser(P);
        } while (P != firstUser(L));
    } else {
        cout << "Kosong" << endl;
    }
}

void showSkor(ListUser& L) {
    int i = 1;
    AddressUser P = firstUser(L);

    if (P != nilUser) {
        cout << "\nDaftar User" << endl;
        do {
            cout << "User-" << i << ": " << infoUser(P).username << endl;
            i++;
            //cout << infoUser(P).skor << endl;
            P = nextUser(P);
        } while (P != firstUser(L));
    } else {
        cout << "Kosong" << endl;
    }
}

void displayParticipantScores(ListUser L) {
    AddressUser P = firstUser(L);

    if (P == nilUser) {
        cout << "Belum ada peserta yang mengikuti kuis." << endl;
        return;
    }

    cout << "+=========================+" << endl;
    cout << "| Daftar Skor Peserta     |" << endl;
    cout << "+=========================+" << endl;

    while (P != nilUser) {
        if (infoUser(P).skor >= 0) {
            cout << "Skor Peserta: " << infoUser(P).skor << endl;
        }
        P = nextUser(P);
    }
}

int countUser(ListUser L) {
    int count = 0;
    AddressUser P = firstUser(L);
    do {
        count++;
        P = nextUser(P);
    } while (P != firstUser(L));
    return count;
}

//belom selesai
void SortDescending(ListUser L){
    ListUser sortedList; //bikin list baru
    if (firstUser(L) == nilUser || nextUser(firstUser(L)) == nilUser) {
    // Jika list kosong atau hanya satu elemen, sudah terurut
        return;
    }
    //ListUser sortedList;
    sortedList.firstUser = L.firstUser;

    AddressUser sorted = nilUser;
    AddressUser current = L.firstUser;

    do  {
        if (infoUser(current).skor != -1) {
           AddressUser next = nextUser(current);


        if (sorted == nilUser || infoUser(current).skor >= infoUser(sorted).skor) {
            prevUser(current) = nilUser;
            nextUser(current) = sorted;

            if (sorted != nilUser) {
                prevUser(sorted) = current;
            }

            sorted = current;
        } else {
            AddressUser temp = sorted;

            while (nextUser(temp) != nilUser && infoUser(current).skor < infoUser(nextUser(temp)).skor) {
                temp = nextUser(temp);
            }

            nextUser(current) = nextUser(temp);
            prevUser(current) = temp;

            if (nextUser(temp) != nilUser) {
                prevUser(nextUser(temp)) = current;
            }

            nextUser(temp) = current;
            }
        }
        current = nextUser(current);
    } while (current != nilUser);
    showAllUser(L);

}

void Quiz(ListUser &LU, ListSoal &LS){


}

