#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int NUM_STUDENTS = 20;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// a. Membaca data siswa
void getData(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Masukkan nama depan siswa ke-" << i + 1 << ": ";
        cin >> students[i].studentFName;
        cout << "Masukkan nama belakang siswa ke-" << i + 1 << ": ";
        cin >> students[i].studentLName;
        cout << "Masukkan nilai ujian: ";
        cin >> students[i].testScore;
        cout << endl;
    }
}

// b. Menentukan grade berdasarkan nilai
void assignGrade(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        int score = students[i].testScore;
        if (score >= 90)
            students[i].grade = 'A';
        else if (score >= 80)
            students[i].grade = 'B';
        else if (score >= 70)
            students[i].grade = 'C';
        else if (score >= 60)
            students[i].grade = 'D';
        else
            students[i].grade = 'F';
    }
}

// c. Mencari nilai tertinggi
int highestScore(studentType students[], int size) {
    int highest = students[0].testScore;
    for (int i = 1; i < size; i++) {
        if (students[i].testScore > highest)
            highest = students[i].testScore;
    }
    return highest;
}

// d. Menampilkan siswa dengan nilai tertinggi
void printHighest(const studentType students[], int size, int highest) {
    cout << "\nSiswa dengan nilai tertinggi (" << highest << "):\n";
    for (int i = 0; i < size; i++) {
        if (students[i].testScore == highest)
            cout << students[i].studentLName << ", " << students[i].studentFName << endl;
    }
}

// Menampilkan semua data siswa
void printData(const studentType students[], int size) {
    cout << left << setw(15) << "Last Name"
         << setw(15) << "First Name"
         << setw(10) << "Score"
         << setw(6) << "Grade" << endl;
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << left << setw(15) << students[i].studentLName
             << setw(15) << students[i].studentFName
             << setw(10) << students[i].testScore
             << setw(6) << students[i].grade << endl;
    }
}

int main() {
    studentType classList[NUM_STUDENTS];
    int highest;

    getData(classList, NUM_STUDENTS);
    assignGrade(classList, NUM_STUDENTS);
    highest = highestScore(classList, NUM_STUDENTS);
    printData(classList, NUM_STUDENTS);
    printHighest(classList, NUM_STUDENTS, highest);

    return 0;
}
