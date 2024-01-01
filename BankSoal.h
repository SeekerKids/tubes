#ifndef BANKSOAL_H_INCLUDED
#define BANKSOAL_H_INCLUDED

#include <iostream>
#include <vector>

#define firstSoal(L) L.firstSoal
#define nextSoal(P) P->nextSoal
#define infoSoal(P) P->infoSoal
#define nilSoal NULL


using namespace std;

struct InfoSoal {
    int indexSoal;
    string pertanyaan;
    string pilihanA;
    string pilihanB;
    string pilihanC;
    char jawaban;
    int countBenar; //buat lihat paling banyak benar atau salah
    int countSalah; //buat lihat paling banyak benar atau salah
};

typedef struct ElmSoal *AdrSoal;

struct ElmSoal {
    InfoSoal infoSoal;
    AdrSoal nextSoal;
};

struct ListSoal {
    AdrSoal firstSoal;
};

void createSoalList(ListSoal &L);

AdrSoal allocateSoal(InfoSoal x);
void insertLastSoal(ListSoal &L, AdrSoal P);
int countSoal(ListSoal L);
void displayAllSoal(ListSoal L);
void addSoal(ListSoal &L);
AdrSoal findSoalByIndex(const ListSoal L, int index);
void editSoal(ListSoal &L);
void displayTopQuestions(/*ListQuiz L,*/ ListSoal &L);


#endif // BANKSOAL_H_INCLUDED
