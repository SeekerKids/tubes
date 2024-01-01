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
        cout << endl;
        cout << "Index : " << infoSoal(P).indexSoal << endl;
        cout << "Pertanyaan:" << endl;
        cout << infoSoal(P).pertanyaan << endl;
        cout << "A. " << infoSoal(P).pilihanA << endl;
        cout << "B. " << infoSoal(P).pilihanB << endl;
        cout << "C. " << infoSoal(P).pilihanC << endl;
        cout << "Jawaban yang benar: " << infoSoal(P).jawaban << endl;
        cout << "---------------------------------" << endl;
        P = nextSoal(P);
    }
}

void addSoal(ListSoal &L){
    AdrSoal Q;
    InfoSoal infoSoal;
    string pertanyaan, pilihanA,pilihanB,pilihanC;
    char jawaban;

    cout << "\n+=============================+" << endl;
    cout << "|        Tambah Soal           |" << endl;
    cout << "+=============================+" << endl;

    cout << "Pertanyaan: ";
    cin >> pertanyaan;
    infoSoal.pertanyaan = pertanyaan;

    cout << "Pilihan A: ";
    cin >> pilihanA;
    cout << "Pilihan B: ";
    cin >> pilihanB;
    cout << "Pilihan C: ";
    cin >> pilihanC;

    cout << "Jawaban: ";
    cin >> jawaban;
    infoSoal.pilihanA = pilihanA;
    infoSoal.pilihanB = pilihanB;
    infoSoal.pilihanC = pilihanC;
    infoSoal.jawaban = jawaban;

    infoSoal.indexSoal = countSoal(L)+1;
    Q = allocateSoal(infoSoal);
    insertLastSoal(L, Q);

    cout << "Soal successfully registered!" << endl;
    return;
}

AdrSoal findSoalByIndex(ListSoal L, int index) {
    AdrSoal P  = firstSoal(L);
    while (P != nilSoal) {
        if (infoSoal(P).indexSoal == index) {
            return P;  // Found the user
        }
        P = nextSoal(P);
    }

    return nilSoal;  // User not found

}

void editSoal(ListSoal &L){
    int editIndex;
    AdrSoal Q;
    InfoSoal infoSoal;
    string pertanyaan, pilihanA,pilihanB,pilihanC;
    char jawaban;

    cout << "\n+=============================+" << endl;
    cout << "|          Edit Soal           |" << endl;
    cout << "+=============================+" << endl;
    cout << "Soal dengan index berapa yang ingin di edit : ";
    cin >> editIndex;
    cout << endl;
    AdrSoal x = findSoalByIndex(L, editIndex);
    if (x == nullptr){
        cout << "Tidak ditemukan Soal dengan index tersebut" << endl;
    } else {
        cout << "";
        cout << "Edit Pertanyaan: ";
        cin >> pertanyaan;
        infoSoal(x).pertanyaan = pertanyaan;

        cout << "Edit Pilihan A: ";
        cin >> pilihanA;
        cout << "Edit Pilihan B: ";
        cin >> pilihanB;
        cout << "Edit Pilihan C: ";
        cin >> pilihanC;

        cout << "Edit Jawaban: ";
        cin >> jawaban;
        cout << endl;
        infoSoal(x).pilihanA = pilihanA;
        infoSoal(x).pilihanB = pilihanB;
        infoSoal(x).pilihanC = pilihanC;
        infoSoal(x).jawaban = jawaban;
        cout << "Soal telah Berhasil di Edit"<<endl;
    }

}
//belom ini
void displayTopQuestions(/*ListQuiz L,*/ ListSoal &L) {
    //vector<AdrSoal> questions;
    /*
    AdrQuiz P = firstQuiz(L);

    while (P != nilQuiz) {
        AdrSoal question = randomSoal(bankSoal);
        char participantAnswer = infoQuiz(P).jawabanPeserta;

        if (participantAnswer == infoSoal(question).jawaban) {
            questions.push_back(question);
        }

        P = nextQuiz(P);
    }
    */
    // Manual insertion sort based on the count of correct answers
/*
    for (int i = 1; i < countSoal(L); ++i) {
        AdrSoal key = questions[i];
        int j = i - 1;

        while (j >= 0 && static_cast<int>(count(questions.begin(), questions.end(), questions[j])) < static_cast<int>(count(questions.begin(), questions.end(), key))) {
            questions[j + 1] = questions[j];
            j = j - 1;
        }

        questions[j + 1] = key;
    }

    cout << "+================================+" << endl;
    cout << "| 5 Pertanyaan Paling Sering ... |" << endl;
    cout << "+================================+" << endl;

    // Display the top 5 questions
    for (int i = 0; i < min(5, static_cast<int>(questions.size())); ++i) {
        cout << "Pertanyaan " << i + 1 << ":" << endl;
        cout << infoSoal(questions[i]).pertanyaan << endl;
        cout << "Jawaban yang benar: " << infoSoal(questions[i]).jawaban << endl;
        cout << "---------------------------------" << endl;
    }

*/
}




