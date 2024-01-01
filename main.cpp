#include <iostream>
#include "User.h"
#include "BankSoal.h"
//#include "Quiz.h"

using namespace std;

void DummyData(ListUser &userList, ListSoal &bankSoal) {
    // Dummy Users
    UserInfo user4 = {"admin", "admin", true, -1};   // Admin user with score
    UserInfo user1 = {"user1", "pass1", false, 20};  // Score initialized to 100
    UserInfo user2 = {"user2", "pass2", false, 50;  // Score initialized to 150
    UserInfo user3 = {"user3", "pass3", false, 30};  // Score initialized to 120

    AddressUser node1 = allocateUser(user1);
    AddressUser node2 = allocateUser(user2);
    AddressUser node3 = allocateUser(user3);
    AddressUser node4 = allocateUser(user4);

    insertLastUser(userList, node1);
    insertLastUser(userList, node2);
    insertLastUser(userList, node3);
    insertLastUser(userList, node4);

    // Dummy Questions in the BankSoal
    int indexSoal;
    string pertanyaan;
    string pilihanA;
    string pilihanB;
    string pilihanC;
    char jawaban;
    int countBenar; //buat lihat paling banyak benar atau salah
    int countSalah;
    InfoSoal soal1 = {1,"Pertanyaan 1", "Jawaban A", "Jawaban B", "Jawaban C", 'A',0,0};
    InfoSoal soal2 = {2,"Pertanyaan 2", "Jawaban A", "Jawaban B", "Jawaban C", 'B',0,0};
    InfoSoal soal3 = {3,"Pertanyaan 3", "Jawaban A", "Jawaban B", "Jawaban C", 'C',0,0};

    AdrSoal question1 = allocateSoal(soal1);
    AdrSoal question2 = allocateSoal(soal2);
    AdrSoal question3 = allocateSoal(soal3);

    insertLastSoal(bankSoal, question1);
    insertLastSoal(bankSoal, question2);
    insertLastSoal(bankSoal, question3);

}

int main() {
    ListUser userList;
    ListSoal bankSoal;

    createUserList(userList);
    createSoalList(bankSoal);


    DummyData(userList, bankSoal);

    int choice, choiceLogin;
    bool loggedIn = false;

    string loggedInUsername;
    string username, password;

    cout << "+==================================+" << endl;
    cout << "|         Selamat Datang Di        |" << endl;
    cout << "|              Program             |" << endl;
    cout << "|                                  |" << endl;
    cout << "|         WHO WANTS TO BE A        |" << endl;
    cout << "|              MILIONER            |" << endl;
    cout << "+==================================+" << endl;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Buat Akun" << endl;
        cout << "2. Login" << endl;
        cout << "3. Tampilkan Daftar Peserta" << endl;
        cout << "4. Test" << endl;
        cout << "0. Keluar Aplikasi" << endl;

        cout << "Pilihan Anda: ";
        cin >> choiceLogin;

        switch (choiceLogin) {
        case 1:
            registerUser(userList);
            break;
        case 2:
            do {
                cout << "Masukkan username: ";
                cin >> username;

                cout << "Masukkan password: ";
                cin >> password;

                if (loginUser(userList, username, password)) {
                    loggedIn = true;
                    loggedInUsername = username;
                    cout << "Login berhasil!" << endl;
                } else {
                    cout << "Login gagal. Periksa kembali username dan password Anda." << endl;
                    cout << "1. Coba lagi" << endl;
                    cout << "0. Kembali ke menu utama" << endl;
                    cout << "Pilihan Anda: ";
                    cin >> choice;
                    if (choice == 0) {
                        loggedIn = false;
                        break;
                    }
                }
            } while (!loggedIn);
            break;
        case 3 :
            showAllUser(userList);
            //SortDescending(userList);
            break;
        case 4:
            countUser(userList);
            break;
        case 0:
            cout << "Terima kasih telah menggunakan aplikasi!" << endl;
            return 0;
        }

        while (loggedIn) {
            // Cek admin
            bool isAdmin = false;
            AddressUser currentUser = findUserByUsername(userList, loggedInUsername);

            if (currentUser != nilUser && infoUser(currentUser).status) {
                isAdmin = true;
            }

            // Menu kalau udah login

            if (!isAdmin) {    /* Menu peserta */
                cout << "\nSelamat datang, " << loggedInUsername << "!" << endl;
                cout << "+==================================+" << endl;
                cout << "|              Main Menu            |" << endl;
                cout << "+==================================+" << endl;
                cout << "1. Mulai Quiz" << endl;
                cout << "2. Tampilkan daftar Peserta Berdasarkan Skor" << endl;
                cout << "3. " << endl; // masih kosong
                cout << "4. " << endl;
                cout << "0. Logout" << endl;

                cout << "Pilihan Anda: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        //Mulai Quis;
                        //Quiz(userList,bankSoal);
                        break;
                    case 2:
                        SortDescending(userList);
                        showSkor(userList);
                        //nampilkan daftar peserrta beserta skor;
                        break;
                    case 3:
                        //
                        break;
                    case 4:
                        //displayTopQuestions(bankSoal);
                        break;
                    case 0:
                        loggedIn = false;
                        loggedInUsername.clear();
                        cout << "Anda berhasil logout." << endl;
                        break;
                    default:
                        cout << "Silahkan Masukkan Input Yang Benar" << endl;
                        break;
                }
            } else {           /* Menu Admin */

                cout << "\nSelamat datang, " << loggedInUsername << "!" << endl;
                cout << "Anda Login Sebagai Admin!" << endl;
                cout << "+==================================+" << endl;
                cout << "|              Main Menu            |" << endl;
                cout << "+==================================+" << endl;
                cout << "1. Tambah Soal Quiz" << endl;
                cout << "2. Edit Soal" << endl;
                cout << "3. Hapus Soal Quiz dan kunci" << endl;
                cout << "4. Tampilkan 5 Soal Paling Sering Benar/Salah" << endl;
                cout << "0. Logout" << endl;

                cout << "Pilihan Anda: ";
                cin >> choice;

                switch (choice) {
                    //cout << "ewe" << endl; // nggak keluar
                    case 1:
                        addSoal(bankSoal);
                        // Kode untuk tambah soal quiz (insert first)
                        break;
                    case 2:
                        displayAllSoal(bankSoal);
                        // Kode untuk edit soal(show dlu semua soalnya
                        editSoal(bankSoal);
                        break;
                    case 3:
                        // Kode untuk hapus soal quiz & kunci (delete last)
                        // kasih disconet klo udah ada relasinya
                        break;
                    case 4:
                        //displayTopQuestions(bankSoal);
                        break;
                    case 0:
                        loggedIn = false;
                        loggedInUsername.clear();
                        cout << "Anda berhasil logout." << endl;
                        break;
                    default:
                        cout << "Silahkan Masukkan Input Yang Benar" << endl;
                        break;
                }
            }
        }
    } while (choiceLogin != 0);

    return 0;
}
