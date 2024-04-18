#include "vektoriai.h"
#include "student.h"

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
    for(const auto& grade : student.getGrades()){
        sum += grade;
    }

    double average = sum / student.getGrades().size();

    return average;
}

double calculateMedian(const Student& student) {
    Student temp = student;

    vector<int> grades = temp.getGrades();

    sort(grades.begin(), grades.end());

    size_t size = grades.size();
    auto middle = grades.begin();
    std::advance(middle, size / 2); 
    if (size % 2 != 0) {
        return static_cast<double>(*middle);
    } else {
        auto prev = middle;
        --prev;
        return static_cast<double>(*prev + *middle) / 2.0;
    }
}

void randomGradeGenerator(int number, Student& student) {
    student.setGrades(vector<int>());
    srand(time(NULL));
    cout << "Namų darbų pažymiai:" << endl;
    for (int i = 0; i < number; i++) {
        int grade;
        do {
            grade = rand() % 10 + 1; 
        } while (!isValidGrade(to_string(grade))); 
        vector<int> grades = student.getGrades(); // Get current grades
        grades.push_back(grade); // Add new grade
        student.setGrades(grades);
        cout << student.getGrades().back() << endl;
    }
    student.setFinalExamGrade(rand() % 10 + 1);
    cout << "Egzamino pažymys: "  << endl << student.getFinalExamGrade() << endl;
}

void generateNames(Student& student) {
    vector<string> firstNames = {"John", "Jane", "Michael", "Emily", "David", "Sarah", "James", "Jessica", "Daniel", "Jennifer"};
    vector<string> lastNames = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"};

    srand(time(NULL));
    random_shuffle(firstNames.begin(), firstNames.end());
    random_shuffle(lastNames.begin(), lastNames.end());

    student.setFirstName(firstNames[rand() % firstNames.size()]); 
    student.setLastName(lastNames[rand() % lastNames.size()]);
    cout << "Sugeneruotas vardas ir pavardė: " << student.getFirstName() << " " << student.getLastName()<< endl;
}

void readFromFile(const string& filename, vector<Student>& students) {
 auto start = chrono::high_resolution_clock::now();
 ifstream file(filename);
    try {
        if (!file.is_open()) {
            throw runtime_error("Failas nebuvo rastas arba negalima atidaryti."); 
        }

        string header, line;
        getline(file, header); 

        while (getline(file, line)) {
            stringstream ss(line);
            Student student;
            ss >> student; // input operator

            student.setFinalAverage(calculateAverage(student) * 0.4 + student.getFinalExamGrade() * 0.6); 
            student.setFinalMedian(calculateMedian(student) * 0.4 + student.getFinalExamGrade() * 0.6);
            
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
    cout << "Įvesties operatorius veikia. \n " << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> time = end - start;
    cout << endl;
    cout << "Skaitymo laikas " << filename << " " << time.count() << " sekundės" << endl;
    cout << endl;
}



bool sortByAverage(const Student& studentA, const Student& studentB) {
    return studentA.getFinalAverage() > studentB.getFinalAverage(); 
}

bool sortByMedian(const Student& studentA, const Student& studentB) {
    return studentA.getFinalMedian() > studentB.getFinalMedian(); 
}

void sortStudents(vector<Student>& students, char option) {
    auto start = chrono::high_resolution_clock::now(); 
    auto stop = chrono::high_resolution_clock::now(); 
    chrono::duration<double> time;

    switch (option) {
        case '1': {
            start = chrono::high_resolution_clock::now(); 
            stop = chrono::high_resolution_clock::now(); 
            break;
        }
        case '2': {
            start = chrono::high_resolution_clock::now();
            sort(students.begin(), students.end(), [](const Student& a, const Student& b) { return a.getFinalAverage() > b.getFinalAverage(); });
            stop = chrono::high_resolution_clock::now();
            break;
        }
        case '3': {
            start = chrono::high_resolution_clock::now();
            sort(students.begin(), students.end(), [](const Student& a, const Student& b) { return a.getFinalMedian() > b.getFinalMedian(); });
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


void printResults(const vector<Student>& students, char sortingOption, const string& outputFilename = "") {
    if (outputFilename.empty()) {
        cout << fixed << setw(10) << "Vardas" << setw(20) << "Pavardė" << setw(25) << "Galutinis (Vid.)" << setw(25) << "Galutinis (Med.)\n";
        cout << "--------------------------------------------------------------------------------------------\n";
        for (const auto& student : students) {
            cout << student; //  output operator 
        }
        cout << "Išvesties operatorius veikia. \n " << endl;
    } else {
        ofstream outputFile(outputFilename);
        if (!outputFile.is_open()) {
            cout << "Neišejo atidaryti: " << outputFilename << endl;
            return;
        }
        outputFile << fixed << setw(10) << "Vardas" << setw(20) << "Pavardė" << setw(25) << "Galutinis (Vid.)" << setw(25) << "Galutinis (Med.)\n";
        outputFile << "--------------------------------------------------------------------------------------------\n";
        for (const auto& student : students) {
            outputFile << student; // output operator 
        }
        outputFile.close();
        cout << "Išvesties operatorius veikia. \n " << "Rezultatus rasite: " << outputFilename << endl;
    }
}


void tests() {
    // Test constructor with parameters
    Student s2("Alice", "Brown");
    assert(s2.getFirstName() == "Alice");
    assert(s2.getLastName() == "Brown");
    assert(s2.getGrades().empty());
    assert(s2.getFinalExamGrade() == 0);
    assert(s2.getMedian() == 0.0);
    assert(s2.getAverage() == 0.0);
    assert(s2.getFinalMedian() == 0.0);
    assert(s2.getFinalAverage() == 0.0);
    assert(s2.getFinalGrade() == 0.0);

    // Test copy constructor
    Student s3 = s2;
    assert(s3.getFirstName() == "Alice");
    assert(s3.getLastName() == "Brown");
    assert(s3.getGrades().empty());
    assert(s3.getFinalExamGrade() == 0);
    assert(s3.getMedian() == 0.0);
    assert(s3.getAverage() == 0.0);
    assert(s3.getFinalMedian() == 0.0);
    assert(s3.getFinalAverage() == 0.0);
    assert(s3.getFinalGrade() == 0.0);

    // Test move constructor
    Student s4 = std::move(s3);
    assert(s4.getFirstName() == "Alice");
    assert(s4.getLastName() == "Brown");
    assert(s4.getGrades().empty());
    assert(s4.getFinalExamGrade() == 0);
    assert(s4.getMedian() == 0.0);
    assert(s4.getAverage() == 0.0);
    assert(s4.getFinalMedian() == 0.0);
    assert(s4.getFinalAverage() == 0.0);
    assert(s4.getFinalGrade() == 0.0);
    assert(s3.getFirstName() == "");
    assert(s3.getLastName() == "");
    assert(s3.getGrades().empty());
    assert(s3.getFinalExamGrade() == 0);
    assert(s3.getMedian() == 0.0);
    assert(s3.getAverage() == 0.0);
    assert(s3.getFinalMedian() == 0.0);
    assert(s3.getFinalAverage() == 0.0);
    assert(s3.getFinalGrade() == 0.0);

    cout << "Visi testai sekmingi!" << endl;
}
