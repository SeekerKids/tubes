#include "BankSoal.h"

void createSoalList(ListSoal &L) {
    firstSoal(L) = nilSoal;
}

AdrSoal allocateSoal(InfoSoal x) {
    AdrSoal p = new ElmSoal;
    infoSoal(p) = x;
    nextSoal(p) = nilSoal;
    return p;
}

void insertLastSoal(ListSoal &L, AdrSoal P) {
    if (firstSoal(L) == nilSoal) {
        nextSoal(P) = nilSoal;
        firstSoal(L) = P;
    } else if (nextSoal(firstSoal(L)) == nilSoal) {
        nextSoal(firstSoal(L)) = P;
        nextSoal(P) = nilSoal;
    } else {
        AdrSoal Q = firstSoal(L);
        while (nextSoal(Q) != nilSoal){
            Q = nextSoal(Q);
        }
        nextSoal(Q) = P;
    }
}

int countSoal(ListSoal L) {
    int count = 0;
    AdrSoal P = firstSoal(L);
    while (P != nilSoal) {
        count++;
        P = nextSoal(P);
    }
    return count;
}

void displayAllSoal(ListSoal L) {
    AdrSoal P = firstSoal(L);
    if (P == nilSoal) {
        cout << "Belum ada soal yang tersedia." << endl;
        return;
    }

    while (P != nilSoal) {
        cout << "Pertanyaan:" << endl;
        cout << infoSoal(P).pertanyaan << endl;
        cout << "A. " << infoSoal(P).pilihanA << endl;
        cout << "B. " << infoSoal(P).pilihanB << endl;
        cout << "C. " << infoSoal(P).pilihanC << endl;
        cout << "Jawaban yang benar: " << infoSoal(P).jawaban << endl;
        cout << "---------------------------------" << endl;
        P =nextSoal(P);
    }
}
