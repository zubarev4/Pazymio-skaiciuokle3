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
        vector<int> grades = student.getGrades(); 
        grades.push_back(grade); 
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

void tests() {
   // Constructor
    {
    vector<int> grades = {10, 9, 8};
    string firstName = "V";
    string lastName = "P";
    int finalExamGrade = 7;
    double median = 9.5;
    double average = 9.0;

    Student student1(firstName, lastName, grades, finalExamGrade, median, average);

    assert(student1.getGrades() == grades && "Klaida: grades");
    assert(student1.getFirstName() == firstName && "Klaida: firstName");
    assert(student1.getLastName() == lastName && "Klaida: lastName");
    assert(student1.getFinalExamGrade() == finalExamGrade && "Klaida: finalExamGrade");
    assert(student1.getMedian() == median && "Klaida: median");
    assert(student1.getAverage() == average && "Klaida: average");
}

    cout << "Parameter constructor :)" << endl;

    // Copy constructor 
    {
    vector<int> grades = {10, 9, 8};
    string firstName = "V";
    string lastName = "P";
    int finalExamGrade = 7;
    double median = 9.5;
    double average = 9.0;

    Student student2(firstName, lastName, grades, finalExamGrade, median, average);
    Student student3(student2);

    assert(student2.getGrades() == student3.getGrades() && "Copy constructor Klaida: Grades");
    assert(student2.getFirstName() == student3.getFirstName() && "Copy constructor Klaida: First name");
    assert(student2.getLastName() == student3.getLastName() && "Copy constructor Klaida: Last name");
    assert(student2.getFinalExamGrade() == student3.getFinalExamGrade() && "Copy constructor Klaida: Final exam grade");
    assert(student2.getAverage() == student3.getAverage() && "Copy constructor Klaida: Average");
    assert(student2.getMedian() == student3.getMedian() && "Copy constructor Klaida: Median");
}

    cout << "Copy constructor :)" << endl;

    // Move constructor
    {
    vector<int> grades = {10, 9, 8};
    string firstName = "V";
    string lastName = "P";
    int finalExamGrade = 7;
    double median = 9.5;
    double average = 9.0;

        Student student2(firstName, lastName, grades, finalExamGrade, median, average);
        Student student3(std::move(student2));

        assert(student2.getFirstName().empty() && "Move constructor Klaida: First name");
        assert(student2.getLastName().empty() && "Move constructor Klaida: Last name");
        assert(student2.getGrades().empty() && "Move constructor Klaida: Grades");
        assert(student2.getFinalExamGrade() == 0 && "Move constructor Klaida: Final exam grade");
        assert(student2.getAverage() == 0 && "Move constructor Klaida: Average");
        assert(student2.getMedian() == 0 && "Move constructor Klaida: Median");
    }

    cout << "Move constructor :)" << endl;

    // Destructor test
    {
        Student student;
        assert(student.getFirstName().empty() && "Destructor Klaida: firstName ");

    }
    
    cout << "Destructor :)" << endl;

    cout << "Visi testai sekmingi" << endl;
}