#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <cctype>
#include <limits> 

using namespace std;

struct Student {
    string firstName;
    string lastName;
    int* grades;
    int numGrades;
    int finalExamGrade;
};

bool isValidName(const string& name) {
    if (name.length() < 2) {
        return false;
    }
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

void randomGradeGenerator(int number, Student& student) {
    student.grades = new int[number];
    student.numGrades = number;
    srand(time(NULL));
    cout << "Namų darbų pažymiai:" << endl;
      for (int i = 0; i < number; i++) {
        int grade;
        do {
            grade = rand() % 10 + 1; 
        } while (!isValidGrade(to_string(grade))); 
        student.grades[i] = grade;
        cout << student.grades[i] << endl;
    }
    student.finalExamGrade = rand() % 10 + 1; 
    cout << "Egzamino pažymys: "  << endl << student.finalExamGrade << endl;
}

int main() {
    int numStudents = 0;
    Student* students = nullptr;
    string firstName, lastName;
    string input, finalExamGrade;

    while (true) {
        cout << "Įveskite studento vardą ir pavardę (įveskite 'baigti vesti', kai norėsite baigti įvestį) :\n" << "Įveskite 'noriu iseiti', jei norite išeiti \n";
        cin >> firstName >> lastName;
        if (firstName == "noriu" && lastName == "iseiti") { 
            return 0;
        }
        
        if (firstName == "baigti" && lastName == "vesti") {
            if (numStudents == 0) {
                cout << "Programa baigta.\n";
                return 0; 
            } else {
                break; 
            }
        }

        if (!isValidName(firstName) || !isValidName(lastName)) {
            cout << "Neteisinga įvestis. Vardas ir pavardė turėtų būti sudaryti tik iš raidžių. Bandykite dar:\n";
            continue;
        }

    Student temp = {firstName, lastName};
    cout << "Ar norite vesti namų darbų pažymius ranka ar generuoti? (r/g): ";
    cin >> input;

    if (input == "r") {
        cout << "Įveskite namų darbų pažymius " << temp.firstName << ' ' << temp.lastName << " (įveskite '-1', kad baigti):\n";
        temp.grades = new int[1]; 
        temp.numGrades = 0;
        string grade;
        while (cin >> grade) {
            if (grade == "-1") {
                break;
            }
            if (isValidGrade(grade)) {
                if (temp.numGrades % 100 == 0) {
                int* newGrades = new int[temp.numGrades + 100]; 
                for (int i = 0; i < temp.numGrades; ++i) {
                    newGrades[i] = temp.grades[i];
                }
                delete[] temp.grades;
                temp.grades = newGrades; 
            }
                temp.grades[temp.numGrades] = stoi(grade);
                temp.numGrades++;
            } else {
                cout << "Neteisinga įvestis. Pažymiai gali būti tik skaičiai nuo 1 iki 10. Bandykite dar: ";
            }
        }

           while (true) {
        cout << "Įveskite egzamino pažymį " << temp.firstName << ' ' << temp.lastName << ":\n";
        cin >> finalExamGrade;
            if (isValidGrade(finalExamGrade)) {
                temp.finalExamGrade = stoi(finalExamGrade);
                numStudents++;
                break;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Neteisinga įvestis. Egzamino pažymys gali būti tik skaičius nuo 1 iki 10." << endl;
            }
     }
    } else if (input == "g") {
        int number;
        cout << "Kiek namų darbų pažymių norite generuoti? ";
        cin >> number;
        randomGradeGenerator(number, temp); 
        numStudents++;
        break; 
    } else {
        cout << "Neteisinga įvestis. Įveskite 'r' arba 'g'.\n";
        continue;
    }

        // Dynamic memory reallocation for students array
        Student* tempArray = new Student[numStudents];
        for (int i = 0; i < numStudents - 1; ++i) {
            tempArray[i] = students[i];
        }
        tempArray[numStudents - 1] = temp;
        delete[] students;
        students = tempArray;
    }


  int calculation;
  while (true) {
    cout << "Įveskite 1, kad paskaičiuoti medianą arba 2 vidurkį: ";
    if (cin >> calculation) {
        switch(calculation){
            case 1: {
                cout << fixed << setw(10) << "Vardas" << setw(20) << "Pavardė" << setw(25) << "Galutinis (Med.)\n";
                cout << "----------------------------------------------------\n";
                for (int i = 0; i < numStudents; i++) {
                    cout << fixed << setw(10) << students[i].firstName << fixed << setw(20) << students[i].lastName;
                    cout << fixed << setw(20) << setprecision(1) << calculateMedian(students[i]) << '\n';
                }
                break;
            }
            case 2: {
                cout << fixed << setw(10) << "Vardas" << setw(20) << "Pavardė" << setw(25) << "Galutinis (Avg.)\n";
                cout << "----------------------------------------------------\n";
                for (int i = 0; i < numStudents; i++) {
                    cout << fixed << setw(10) << students[i].firstName << fixed << setw(20) << students[i].lastName;
                    cout << fixed << setw(20) << setprecision(1) << calculateAverage(&students[i]) * 0.4 + students[i].finalExamGrade * 0.6 << '\n';
                }
                break;
            }
            default:
                cout << "Neteisinga įvestis. Įveskite 1 arba 2.\n";
                continue;
        }
        break; 
    } else {
        cout << "Neteisinga įvestis. Įveskite 1 arba 2.\n";
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
}
    delete[] students;

    return 0;
}
