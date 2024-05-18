#include "vector.h"
#include "student.h"
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
    for(const auto& grade : student.getGrades()){
        sum += grade;
    }

    double average = sum / student.getGrades().size();

    return average;
}

double calculateMedian(const Student& student) {
    Student temp = student;

    Vector<int> grades = temp.getGrades();

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
    student.setGrades(Vector<int>());
    srand(time(NULL));
    cout << "Namų darbų pažymiai:" << endl;
    for (int i = 0; i < number; i++) {
        int grade;
        do {
            grade = rand() % 10 + 1; 
        } while (!isValidGrade(to_string(grade))); 
        Vector<int> grades = student.getGrades(); 
        grades.push_back(grade); 
        student.setGrades(grades);
        cout << student.getGrades().back() << endl;
    }
    student.setFinalExamGrade(rand() % 10 + 1);
    cout << "Egzamino pažymys: "  << endl << student.getFinalExamGrade() << endl;
}

void generateNames(Student& student) {
    Vector<string> firstNames = {"John", "Jane", "Michael", "Emily", "David", "Sarah", "James", "Jessica", "Daniel", "Jennifer"};
    Vector<string> lastNames = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"};

    srand(time(NULL));
    random_shuffle(firstNames.begin(), firstNames.end());
    random_shuffle(lastNames.begin(), lastNames.end());

    student.setFirstName(firstNames[rand() % firstNames.size()]); 
    student.setLastName(lastNames[rand() % lastNames.size()]);
    cout << "Sugeneruotas vardas ir pavardė: " << student.getFirstName() << " " << student.getLastName()<< endl;
}

void readFromFile(const string& filename, Vector<Student>& students) {
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


// testing rule of five
void tests() {
   // Constructor
    {
    Vector<int> grades = {10, 9, 8};
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
    Vector<int> grades = {10, 9, 8};
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
    Vector<int> grades = {10, 9, 8};
    string firstName = "V";
    string lastName = "P";
    int finalExamGrade = 7;
    double median = 9.5;
    double average = 9.0;

        Student student2(firstName, lastName, grades, finalExamGrade, median, average);
        Student student3(std::move(student2));

        assert(student3.getFirstName() == firstName && "Move constructor Klaida s3: First name");
        assert(student3.getLastName() == lastName && "Move constructor Klaida s3: Last name");
        assert(student3.getGrades() == grades && "Move constructor Klaida s3: Grades");
        assert(student3.getFinalExamGrade() == finalExamGrade && "Move constructor Klaida s3: Final exam grade");
        assert(student3.getMedian() == median && "Move constructor Klaida s3: Median");
        assert(student3.getAverage() == average && "Move constructor Klaida s3: Average");


        assert(student2.getFirstName().empty() && "Move constructor Klaida: First name");
        assert(student2.getLastName().empty() && "Move constructor Klaida: Last name");
        assert(student2.getGrades().empty() && "Move constructor Klaida: Grades");
        assert(student2.getFinalExamGrade() == 0 && "Move constructor Klaida: Final exam grade");
        assert(student2.getAverage() == 0 && "Move constructor Klaida: Average");
        assert(student2.getMedian() == 0 && "Move constructor Klaida: Median");
    }

    cout << "Move constructor :)" << endl;

// Copy assignment operator
    {
        Vector<int> grades = {10, 9, 8};
        string firstName = "V";
        string lastName = "P";
        int finalExamGrade = 7;
        double median = 9.5;
        double average = 9.0;

        Student student1(firstName, lastName, grades, finalExamGrade, median, average);
        Student student2;
        student2 = student1;

        assert(student2.getGrades() == student1.getGrades() && "Copy assignment Klaida: Grades");
        assert(student2.getFirstName() == student1.getFirstName() && "Copy assignment Klaida: First name");
        assert(student2.getLastName() == student1.getLastName() && "Copy assignment Klaida: Last name");
        assert(student2.getFinalExamGrade() == student1.getFinalExamGrade() && "Copy assignment Klaida: Final exam grade");
        assert(student2.getAverage() == student1.getAverage() && "Copy assignment Klaida: Average");
        assert(student2.getMedian() == student1.getMedian() && "Copy assignment Klaida: Median");
    }
    cout << "Copy assignment operator :)" << endl;

    // Move assignment operator
    {
        Vector<int> grades = {10, 9, 8};
        string firstName = "V";
        string lastName = "P";
        int finalExamGrade = 7;
        double median = 9.5;
        double average = 9.0;

        Student student1(firstName, lastName, grades, finalExamGrade, median, average);
        Student student2;
        student2 = std::move(student1);

        assert(student2.getFirstName() == firstName && "Move assignment Klaida s2: First name");
        assert(student2.getLastName() == lastName && "Move assignment Klaida s2: Last name");
        assert(student2.getGrades() == grades && "Move assignment Klaida s2: Grades");
        assert(student2.getFinalExamGrade() == finalExamGrade && "Move assignment Klaida s2: Final exam grade");
        assert(student2.getMedian() == median && "Move assignment Klaida s2: Median");
        assert(student2.getAverage() == average && "Move assignment Klaida s2: Average");

        assert(student1.getFirstName().empty() && "Move assignment Klaida: First name");
        assert(student1.getLastName().empty() && "Move assignment Klaida: Last name");
        assert(student1.getGrades().empty() && "Move assignment Klaida: Grades");
        assert(student1.getFinalExamGrade() == 0 && "Move assignment Klaida: Final exam grade");
        assert(student1.getAverage() == 0 && "Move assignment Klaida: Average");
        assert(student1.getMedian() == 0 && "Move assignment Klaida: Median");
    }
    cout << "Move assignment operator :)" << endl;
    
    // Destructor test
    {
        Student student;
        assert(student.getFirstName().empty() && "Destructor Klaida: firstName ");

    }
    
    cout << "Destructor :)" << endl;

    cout << "Visi testai sekmingi" << endl;
}

// checking 5 functions pop_back, push_back, shrink_to_fit, begin, resize
void checkVector() {
    cout << " Tikrinamas pop_back()" << endl;
    {
        Vector<int> myVector;
        int sum = 0;
        myVector.push_back(100);
        myVector.push_back(200);
        myVector.push_back(300);

        while (!myVector.empty()) {
            sum += myVector.back();
            myVector.pop_back();
        }

        cout << "myVector elementai susideda į sumą: " << sum << '\n';
    }

    cout << " Tikrinamas shrink_to_fit()" << endl;
    {
        Vector<int> myVector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        myVector.reserve(20);
        cout << "Talpa prieš shrink_to_fit: " << myVector.capacity() << endl;
        myVector.shrink_to_fit();
        cout << "Talpa po shrink_to_fit: " << myVector.capacity() << endl;
    
    }

    cout << " Tikrinamas begin()" << endl;
    {
        Vector<int> myVector;
        for (int i = 1; i <= 5; i++) myVector.push_back(i);

        cout << "myVector susideda iš:";
        for (Vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
        cout << ' ' << *it;
        cout << '\n';
    }

    cout << " Tikrinamas resize()" << endl;
    {
        Vector<int> myVector;
        // initial
        for (int i = 1; i < 10; i++) myVector.push_back(i);

        myVector.resize(5);
        myVector.resize(8, 100);
        myVector.resize(12);

        cout << "myVector susideda iš:";
        for (Vector<int>::size_type i = 0; i < myVector.size(); i++)
            cout << ' ' << myVector[i];
        cout << '\n';
    }

    cout << " Tikrinamas push_back()" << endl;
    {
        Vector<int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);

        cout << "myVector susideda iš:";
        for (Vector<int>::size_type i = 0; i < myVector.size(); i++)
            cout << ' ' << myVector[i];
        cout << '\n';
    }
}


// std::vector vs Vector efficiency
void vectorVsVector() { 
                auto start = chrono::steady_clock::now();
                unsigned int sz = 100000000;  // 10000, 100000, 1000000, 10000000, 100000000
                vector<int> v1;
                int stdVector = 0;
                for (unsigned int i = 1; i <= sz; ++i) {
                    v1.push_back(i);
                    if (v1.capacity() == v1.size()) {
                        ++stdVector;
                    }
                }
                auto end = chrono::steady_clock::now();
                auto skirtumas = chrono::duration<double> (end - start).count();   
                cout << "Tusčių vektorių su std::vector užpildymas su " << sz << " užėme: " << setprecision(8) << skirtumas << " sekundes" << endl; 
                cout << "Atmintis buvo perskirstyta " << stdVector << " kartų su std::vector" << endl;

                auto start1 = chrono::steady_clock::now();
                Vector<int> v2;
                int vectorx = 0;
               for (unsigned int i = 1; i <= sz; ++i) {
                    v2.push_back(i);
                    if (v2.capacity() == v2.size()) {
                        ++vectorx;
                    }
                }
                
                auto end1 = chrono::steady_clock::now();
                auto skirtumas1 = chrono::duration<double> (end1 - start1).count(); 
                cout << "Tusčių vektorių su Vector užpildymas su " << sz << " užėme: " << setprecision(8) << skirtumas1 << " sekundes" << endl;   
                cout << "Atmintis buvo perskirstyta " << vectorx << " kartų su Vector" << endl;
}