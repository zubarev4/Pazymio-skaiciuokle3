#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <cctype>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    int* grades;
    int numGrades;
    int finalExamGrade;
};

bool isValidName(const string& name) {
    for (char c : name) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

bool isValidGrade(const string& grade) {
    for (char c : grade) {
        if (!isdigit(c)) {
            return false;
        }
    }
    int value = stoi(grade);
    return (value >= 1 && value <= 10);
}

double calculateAverage(Student* student){
    double sum = 0;
    for(int i = 0; i < student->numGrades; i++){
        sum += student->grades[i];
    }

    double average = sum / student->numGrades;

    return average;
}

double calculateMedian(Student& student){
    int* gradesCopy = new int[student.numGrades];
    for(int i = 0; i < student.numGrades; i++){
        gradesCopy[i] = student.grades[i];
    }

    sort(gradesCopy, gradesCopy + student.numGrades);
    double median = 0;
    if(student.numGrades % 2 != 0){
        median = (double)gradesCopy[student.numGrades / 2];
    }
    else{
        median = (double)(gradesCopy[(student.numGrades - 1) / 2] + gradesCopy[student.numGrades / 2]) / 2.0;
    }

    delete[] gradesCopy;

    return median;
}

int main() {
    Student students[3];
    int numStudents = 0;

    for (int i = 0; i < 3; ++i) {
        cout << "Įveskite vardą ir pavardę studento nr " << i + 1 << ":\n";
        cin >> students[i].firstName >> students[i].lastName;
    
        while (!isValidName(students[i].firstName)) {
            cout << "Neteisinga įvestis. Vardas turėtų būti sudarytas tik iš raidžių. Bandykite dar: ";
            cin >> students[i].firstName;
        }

        while (!isValidName(students[i].lastName)) {
            cout << "Neteisinga įvestis. Pavardė turėtų būti sudarytas tik iš raidžių. Bandykite dar: ";
            cin >> students[i].lastName;
        }

        cout << "Įveskite namų darbų pažymius " << students[i].firstName << ' ' << students[i].lastName << " (įveskite '-1', kad baigti):\n";
        students[i].grades = new int[100];
        students[i].numGrades = 0;
        string grade;
        while (cin >> grade) {
            if (grade == "-1") {
                break;
            }
            if (isValidGrade(grade)) {
                students[i].grades[students[i].numGrades] = stoi(grade);
                students[i].numGrades++;
            } else {
                cout << "Neteisinga įvestis. Pažymiai gali būti tik skaičiai nuo 1 iki 10. Bandykite dar: ";
            }
        }

        cout << "Įveskite egzamino pažymį " << students[i].firstName << ' ' << students[i].lastName << ":\n";
        string finalExamGrade;
        cin >> finalExamGrade;
        if (isValidGrade(finalExamGrade)) {
            students[i].finalExamGrade = stoi(finalExamGrade);
            numStudents++;
        } else {
            cout << "Neteisinga įvestis. Egzamino pažymys gali būti tik skaičius nuo 1 iki 10. Bandykite dar: ";
        }
    }

    int option;
    cout << "Įveskite 1, kad paskaičiuoti medianą arba 2 vidurkį: ";
    cin >> option;

    switch(option){
        case 1: {
            cout << fixed << setw(10) << "Vardas" << setw(20) << "Pavardė" << setw(20) << "Galutinis (Med.)\n";
            cout << "----------------------------------------------------\n";
            for (int i = 0; i < 3; i++) {
                cout << fixed << setw(10) << students[i].firstName << fixed << setw(20) << students[i].lastName;
                cout << fixed << setw(20) << setprecision(1) << calculateMedian(students[i]) << '\n';
            }
            break;
        }
        case 2: {
            cout << fixed << setw(10) << "Vardas" << setw(20) << "Pavardė" << setw(25) << "Galutinis (Avg.)\n";
            cout << "----------------------------------------------------\n";
            for (int i = 0; i < 3; i++) {
                cout << fixed << setw(10) << students[i].firstName << fixed << setw(20) << students[i].lastName;
                cout << fixed << setw(20) << setprecision(1) << calculateAverage(&students[i]) * 0.4 + students[i].finalExamGrade * 0.6 << '\n';
            }
            break;
        }
        default:
            cout << "Neteisinga įvestis. Įveskite 1 arba 2.\n";
    }

    for (int j = 0; j < 3; ++j) {
        delete[] students[j].grades;
    }

    return 0;
}