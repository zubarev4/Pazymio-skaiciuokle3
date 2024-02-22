#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <numeric>
#include <chrono>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    vector<int> grades;
    int finalExamGrade;
    double median, average;
    double fin_median, fin_average;
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

double calculateMedian(const Student& student) {
    Student temp = student; 
    sort(temp.grades.begin(), temp.grades.end());

    if (temp.grades.empty()) {
        return 0.0;
    }
    size_t size = temp.grades.size();
    if (size % 2 != 0) {
        return static_cast<double>(temp.grades[size / 2]);
    } else {
        return static_cast<double>(temp.grades[size / 2 - 1] + temp.grades[size / 2]) / 2.0;
    }
}

void randomGradeGenerator(int number, Student& student) {
    student.grades.clear();
    srand(time(NULL));
    cout << "Namų darbų pažymiai:" << endl;
    for (int i = 0; i < number; i++) {
        int grade;
        do {
            grade = rand() % 10 + 1; 
        } while (!isValidGrade(to_string(grade))); 
        student.grades.push_back(grade);
        cout << student.grades.back() << endl;
    }
    student.finalExamGrade = rand() % 10 + 1; 
    cout << "Egzamino pažymys: "  << endl << student.finalExamGrade << endl;
}

void generateNames(Student& student) {
    vector<string> firstNames = {"John", "Jane", "Michael", "Emily", "David", "Sarah", "James", "Jessica", "Daniel", "Jennifer"};
    vector<string> lastNames = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"};

    srand(time(NULL));
    random_shuffle(firstNames.begin(), firstNames.end());
    random_shuffle(lastNames.begin(), lastNames.end());

    student.firstName = firstNames[rand() % firstNames.size()];
    student.lastName = lastNames[rand() % lastNames.size()];
    cout << "Sugeneruotas vardas ir pavardė: " << student.firstName << " " << student.lastName << endl;
}

void readFromFile(const string& filename, vector<Student>& students) {
 auto start = chrono::high_resolution_clock::now();
 ifstream file(filename);
    if (!file.is_open()) {
        cout << "Neišejo nuskaityti: " << filename << endl;
        return;
    }

    string header, line, firstName, lastName;
    getline(file, header); 

    while (getline(file, line)) {
        stringstream ss(line);
        ss >> firstName >> lastName;
        Student student;
        student.firstName = firstName;
        student.lastName = lastName;

        int grade;
        while (ss >> grade) {
            student.grades.push_back(grade);
        }
        if(!student.grades.empty())
        {
            student.finalExamGrade = student.grades.back();
            student.grades.pop_back();
        }
        student.fin_average = calculateAverage(student) * 0.4 + student.finalExamGrade * 0.6;
        student.fin_median = calculateMedian(student) * 0.4 + student.finalExamGrade * 0.6;
        
        students.push_back(student);
    }

    file.close();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> time = end - start;
    cout << "Skaitymo laikas: " << time.count() << endl;
}


bool sortByAverage(const Student& studentA, const Student& studentB) {
    return studentA.fin_average > studentB.fin_average;
}

bool sortByMedian(const Student& studentA, const Student& studentB) {
    return studentA.fin_median > studentB.fin_median;
}

void sortStudents(vector<Student>& students, char option) {
    switch (option) {
        case '1':
            break;
        case '2':
            sort(students.begin(), students.end(), sortByAverage);
            break;
        case '3':
            sort(students.begin(), students.end(), sortByMedian);
            break;
        default:
            cout << "Neteisingas pasirinkimas" << endl;
    }
}

void printResults(const vector<Student>& students, char sortingOption, const string& outputFilename = "") {
    if (outputFilename.empty()) {
        cout << fixed << setw(10) << "Vardas" << setw(20) << "Pavardė" << setw(25) << "Galutinis (Vid.)" << setw(25) << "Galutinis (Med.)\n";
        cout << "--------------------------------------------------------------------------------------------\n";
        for (int i = 0; i < students.size(); i++) {
            cout << fixed << setw(10) << students[i].firstName << setw(20) << students[i].lastName;
            cout << fixed << setw(20) << setprecision(2) << students[i].fin_average;
            cout << fixed << setw(25) << setprecision(2) << students[i].fin_median << '\n';
        }
    } else {
        ofstream outputFile(outputFilename);
        if (!outputFile.is_open()) {
            cout << "Neišejo atidaryti: " << outputFilename << endl;
            return;
        }
        outputFile << fixed << setw(10) << "Vardas" << setw(20) << "Pavardė" << setw(25) << "Galutinis (Vid.)" << setw(25) << "Galutinis (Med.)\n";
        outputFile << "--------------------------------------------------------------------------------------------\n";
        for (int i = 0; i < students.size(); i++) {
            outputFile << fixed << setw(10) << students[i].firstName << setw(20) << students[i].lastName;
            outputFile << fixed << setw(20) << setprecision(2) << students[i].fin_average;
            outputFile << fixed << setw(25) << setprecision(2) << students[i].fin_median << '\n';
        }
        outputFile.close();
        cout << "Rezultatus rasite: " << outputFilename << endl;
    }
}

int main() {
    int numStudents = 0;
    vector<Student> students;
    string firstName, lastName;
    string input, grade, finalExamGrade, choice, option, line, filename;
    Student temp; 
        
    cout << "1 - Jei norite nuskaityti iš failo \n" << "2 - Jei norite vesti duomenis \n";
    cin >> option; 
        switch (option [0]){
    case '1' :

    cout << "Iš kurio failo norite nuskaityti?" << endl;
    cout << "1 - studentai10000.txt" << endl;
    cout << "2 - studentai100000.txt" << endl;
    cout << "3 - studentai1000000.txt" << endl;
    cout << "4 - kursiokai.txt" << endl;
    char fileOption;
    cin >> fileOption;

    switch (fileOption) {
        case '1':
            filename = "studentai10000.txt";
            break;
        case '2':
            filename = "studentai100000.txt";
            break;
        case '3':
            filename = "studentai1000000.txt";
            break;
        case '4':
            filename = "kursiokai.txt";
            break;
        default:
            cout << "Neteisinga įvestis" << endl;
            return 1;
    }

    readFromFile(filename, students);

    cout << "Kaip norėtumėte surikiuoti rezultatus?" << endl;
    cout << "1 - Pagal vardą ir pavardę" << endl;
    cout << "2 - Pagal vidurkį (nuo didžiausio)" << endl;
    cout << "3 - Pagal medianą (nuo didžiausios)" << endl;
    char sortingOption;
    cin >> sortingOption;

    sortStudents(students, sortingOption);

    cout << "Kaip norėtumėte išvesti rezultatus?" << endl;
    cout << "1 - Į ekraną" << endl;
    cout << "2 - Į failą 'results.txt'" << endl;
    cin >> fileOption;

    if (fileOption == '2') {
        printResults(students, sortingOption, "results.txt");
    } else if (fileOption == '1'){
        printResults(students, sortingOption, "");
    }
    else {
        cout << "Neteisinga įvestis" << endl;
    }
            break;

        case '2' :
    while (true) {
        cout << "Ar norite generuoti studento vardą ir pavardę ar įvesti ranka? (g/r): \n" << "Įveskite 'baigti', kai norėsite baigti įvestį \n"  << "Įveskite 'iseiti', jei norite išeiti \n";
        cin >> choice;
        if (choice == "iseiti") { 
            return 0;
        }
        if (choice == "baigti") {
            if (numStudents == 0) {
                cout << "Programa baigta.\n";
                return 0; 
            } else {
                break; 
            }
        }
        switch (choice[0]) {
            case 'r':
            while(true){
                    cout << "Įveskite studento vardą ir pavardę :\n";
                    cin >> firstName >> lastName;
                    if (firstName == "iseiti") { 
                        return 0;
                    }
                    if (firstName == "baigti") {
                        if (numStudents == 0) {
                            cout << "Programa baigta.\n";
                            return 0; 
                        } else {
                            break; 
                        }
                    }
                    if (!isValidName(firstName) || !isValidName(lastName)) {
                        cout << "Neteisinga įvestis. Vardas ir pavardė turėtų būti sudaryti bent iš 2 raidžių. \n";
                        continue;
                    }
                    break;
        }
                    temp = {firstName, lastName}; 

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
                    cout << "Neteisinga įvestis. Pažymiai gali būti tik skaičiai nuo 1 iki 10. " << endl;
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
 }      else if (input == "g") {
            int number;
            while (true) {
                cout << "Kiek namų darbų pažymių norite generuoti? ";
                if (cin >> number) {
                    randomGradeGenerator(number, temp);
                    numStudents++;
                    break; 
                } else {
                    cout << "Neteisinga įvestis. Įveskite skaičių.\n";
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                }
            }
 }
                     else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Neteisinga įvestis. Įveskite 'r' arba 'g'.\n";
                        continue;
                    }
                students.push_back(temp);
                break;

            case 'g':
            generateNames(temp);
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
                    cout << "Neteisinga įvestis. Pažymiai gali būti tik skaičiai nuo 1 iki 10. " << endl;
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
                    } else {
                        cout << "Neteisinga įvestis. Įveskite 'r' arba 'g'.\n";
                        continue;
                    }
                students.push_back(temp);
                break;

            default:
                cout << "Neteisinga įvestis. Pasirinkite 'g' arba 'r'.\n";
                break;
        }
    }

                cout << fixed << setw(10) << "Vardas" << setw(20) << "Pavardė" << setw(25) << "Galutinis (Vid.)" << setw(25) << "Galutinis (Med.)\n";
                cout <<"--------------------------------------------------------------------------------------------\n";
                for (const auto& student : students) {
                    cout << fixed << setw(10) << student.firstName << setw(20) << student.lastName;
                    cout << fixed << setw(20) << setprecision(2)<< calculateAverage(student)*0.4+student.finalExamGrade*0.6;
                    cout << fixed << setw(25) << setprecision(2)<< calculateMedian(student)*0.4+student.finalExamGrade*0.6 << '\n';
                }

            break; 

        default:
            cout << "Neteisinga įvestis. Pasirinkite 1 arba 2.\n";
            break;
        }
        

    return 0;
}