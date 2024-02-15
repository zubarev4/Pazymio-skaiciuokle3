#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <cctype>
#include <vector>
#include <limits> 

using namespace std;

struct Student {
    string firstName;
    string lastName;
    vector<int> grades;
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

double calculateAverage(const Student& student){
    double sum = 0;
    for(const auto& grade : student.grades){
        sum += grade;
    }

    double average = sum / student.grades.size();

    return average;
}

double calculateMedian(const Student& student){
    Student temp = student; // Create a copy of the Student object
    sort(temp.grades.begin(), temp.grades.end());
    if(temp.grades.size() % 2 != 0){
        return (double)temp.grades[temp.grades.size() / 2];
    }
    return (double)(temp.grades[(temp.grades.size() - 1) / 2] + temp.grades[temp.grades.size() / 2]) / 2.0;
}

void randomGradeGenerator(int number, Student& student) {
    student.grades.clear();
    srand(time(NULL));
    cout << "Namų darbų pažymiai:" << endl;
    for (int i = 0; i < number; i++) {
        int grade;
        do {
            grade = rand() % 10 + 1; // Generate a random number between 1 and 10
        } while (!isValidGrade(to_string(grade))); // Check if the generated grade is valid
        student.grades.push_back(grade);
        cout << student.grades.back() << endl;
    }
    student.finalExamGrade = rand() % 10 + 1; // Generate a random final exam grade between 1 and 10
    cout << "Egzamino pažymys: "  << endl << student.finalExamGrade << endl;
}

int main() {
    int numStudents = 0;
    vector<Student> students;
    string firstName, lastName;
    string input, grade, finalExamGrade;

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
            while (cin >> grade) {
                if (grade == "-1") {
                    break;
                }
                if (isValidGrade(grade)) {
                    temp.grades.push_back(stoi(grade));
                } else {
                    cout << "Neteisinga įvestis. Pažymiai gali būti tik skaičiai nuo 1 iki 10. Bandykite dar: ";
                }
            }
            cout << "Įveskite egzamino pažymį " << temp.firstName << ' ' << temp.lastName << ":\n";
            cin >> finalExamGrade;
            if (isValidGrade(finalExamGrade)) {
                temp.finalExamGrade = stoi(finalExamGrade);
                numStudents++;
            } else {
                cout << "Neteisinga įvestis. Egzamino pažymys gali būti tik skaičius nuo 1 iki 10. Bandykite dar: ";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                continue;
            }
        } else if (input == "g") {
            int number;
            cout << "Kiek namų darbų pažymių norite generuoti? ";
            cin >> number;
            randomGradeGenerator(number, temp); 
            numStudents++;
        } else {
            cout << "Neteisinga įvestis. Įveskite 'r' arba 'g'.\n";
            continue;
        }

        students.push_back(temp);
    }

    int calculation;
    while (true) {
        cout << "Įveskite 1, kad paskaičiuoti medianą arba 2 vidurkį: ";
        if (cin >> calculation) {
            switch(calculation){
                case 1: {
                    cout << fixed << setw(10) << "Vardas" << setw(20) << "Pavardė" << setw(25) << "Galutinis (Med.)\n";
                    cout << "----------------------------------------------------\n";
                    for (const auto& student : students) {
                        cout << fixed << setw(10) << student.firstName << fixed << setw(20) << student.lastName;
                        cout << fixed << setw(20) << setprecision(1) << calculateMedian(student) << '\n';
                    }
                    break;
                }
                case 2: {
                    cout << fixed << setw(10) << "Vardas" << setw(20) << "Pavardė" << setw(25) << "Galutinis (Avg.)\n";
                    cout << "----------------------------------------------------\n";
                    for (const auto& student : students) {
                        cout << fixed << setw(10) << student.firstName << fixed << setw(20) << student.lastName;
                        cout << fixed << setw(20) << setprecision(1) << calculateAverage(student) * 0.4 + student.finalExamGrade * 0.6 << '\n';
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

    return 0;
}
