#include "list.h"

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
    temp.grades.sort();

    if (temp.grades.empty()) {
        return 0.0;
    }

    size_t size = temp.grades.size();
    auto middle = temp.grades.begin();
    std::advance(middle, size / 2); // Move the iterator to the middle of the list

    if (size % 2 != 0) {
        return static_cast<double>(*middle);
    } else {
        auto prev = middle;
        --prev;
        return static_cast<double>(*prev + *middle) / 2.0;
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

int randomInt(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

void generateNames(Student& student) {
    list<string> firstNames = {"John", "Jane", "Michael", "Emily", "David", "Sarah", "James", "Jessica", "Daniel", "Jennifer"};
    list<string> lastNames = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"};

    // Generate random indices to select random first and last names
    int firstNameIndex = randomInt(0, firstNames.size() - 1);
    int lastNameIndex = randomInt(0, lastNames.size() - 1);

    // Advance iterators to selected indices
    auto firstNameIter = firstNames.begin();
    advance(firstNameIter, firstNameIndex);

    auto lastNameIter = lastNames.begin();
    advance(lastNameIter, lastNameIndex);

    // Assign random names to the student
    student.firstName = *firstNameIter;
    student.lastName = *lastNameIter;

    cout << "Generated first name and last name: " << student.firstName << " " << student.lastName << endl;
}

void readFromFile(const string& filename, list<Student>& students) {
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
            if (!student.grades.empty()) {
                student.finalExamGrade = student.grades.back();
                student.grades.pop_back();
            }
            student.fin_average = calculateAverage(student) * 0.4 + student.finalExamGrade * 0.6;
            student.fin_median = calculateMedian(student) * 0.4 + student.finalExamGrade * 0.6;

            students.push_back(student);
        }
    } catch (const ifstream::failure& e) {
        cout << "Klaida nuskaitant failą: " << e.what() << endl;
        exit(EXIT_FAILURE);
    } catch (const exception& e) {
        cout << "Klaida: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
    file.close();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> time = end - start;
    cout << endl;
    cout << "Skaitymo laikas " << filename << " " << time.count() << " sekundės" << endl;
    cout << endl;
}



bool sortByAverage(const Student& studentA, const Student& studentB) {
    return studentA.fin_average > studentB.fin_average;
}

bool sortByMedian(const Student& studentA, const Student& studentB) {
    return studentA.fin_median > studentB.fin_median;
}

void sortStudents(list<Student>& students, char option) {
    auto start = chrono::high_resolution_clock::now();
    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double> time;

    switch (option) {
        case '1': {
            // No sorting for case 1
            break;
        }
        case '2': {
            start = chrono::high_resolution_clock::now();
            students.sort([](const Student& a, const Student& b) { return a.fin_average > b.fin_average; });
            stop = chrono::high_resolution_clock::now();
            break;
        }
        case '3': {
            start = chrono::high_resolution_clock::now();
            students.sort([](const Student& a, const Student& b) { return a.fin_median > b.fin_median; });
            stop = chrono::high_resolution_clock::now();
            break;
        }
        default: {
            cout << "Neteisinga įvestis. Turite įrašyti 1/2/3. " << endl;
            exit(EXIT_FAILURE);
        }
    }

    time = stop - start;
    cout << "Rūšiavimas užtruko " << time.count() << " sekundės " << endl;
}

void printResults(const list<Student>& students, char sortingOption, const string& outputFilename = "") {
    if (outputFilename.empty()) {
        cout << fixed << setw(10) << "Vardas" << setw(20) << "Pavardė" << setw(25) << "Galutinis (Vid.)" << setw(25) << "Galutinis (Med.)\n";
        cout << "--------------------------------------------------------------------------------------------\n";
        for (const auto& student : students) {
            cout << fixed << setw(10) << student.firstName << setw(20) << student.lastName;
            cout << fixed << setw(20) << setprecision(2) << student.fin_average;
            cout << fixed << setw(25) << setprecision(2) << student.fin_median << '\n';
        }
    } else {
        ofstream outputFile(outputFilename);
        if (!outputFile.is_open()) {
            cout << "Neišejo atidaryti: " << outputFilename << endl;
            return;
        }
        outputFile << fixed << setw(10) << "Vardas" << setw(20) << "Pavardė" << setw(25) << "Galutinis (Vid.)" << setw(25) << "Galutinis (Med.)\n";
        outputFile << "--------------------------------------------------------------------------------------------\n";
        for (const auto& student : students) {
            outputFile << fixed << setw(10) << student.firstName << setw(20) << student.lastName;
            outputFile << fixed << setw(20) << setprecision(2) << student.fin_average;
            outputFile << fixed << setw(25) << setprecision(2) << student.fin_median << '\n';
        }
        outputFile.close();
        cout << "Rezultatus rasite: " << outputFilename << endl;
    }
}

