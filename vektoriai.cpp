#include "vektoriai.h"

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
    try {
        if (!file.is_open()) {
            throw runtime_error("Failas nebuvo rastas arba negalima atidaryti."); 
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
            if(!student.grades.empty()) {
                student.finalExamGrade = student.grades.back();
                student.grades.pop_back();
            }
            student.fin_average = calculateAverage(student) * 0.4 + student.finalExamGrade * 0.6;
            student.fin_median = calculateMedian(student) * 0.4 + student.finalExamGrade * 0.6;
            
            students.push_back(student);
        }
    } catch(const ifstream::failure& e) {
        cout << "Klaida nuskaitant failą: " << e.what() << endl;
        exit(EXIT_FAILURE); 
    } catch(const exception& e) {
        cout << "Klaida: " << e.what() << endl;
        exit(EXIT_FAILURE); 
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
            cout << "Neteisinga įvestis. Turite įrašyti 1/2/3. " << endl;
            exit(EXIT_FAILURE);

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
