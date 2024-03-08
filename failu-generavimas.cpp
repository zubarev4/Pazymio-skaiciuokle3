#include "failu-generavimas.h"

void writeCategorizedStudents(const vector<Student>& students, const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "Neišeina atidaryti: " << filename << endl;
        return;
    }

    for (const auto& student : students) {
        outputFile << student.firstName << " " << student.lastName << " " << student.finalExamGrade << endl;
    }

    outputFile.close();
    cout << "Surušiotus studentus rasite: " << filename << endl;
}

void generateGrades(Student& student, int numGrades) {
    student.grades.clear();
    srand(time(NULL));
    for (int i = 0; i < numGrades; ++i) {
        int grade = rand() % 10 + 1; // Generate a random grade between 1 and 10
        student.grades.push_back(grade);
        cout << student.grades.back() << endl;
    }
}

// Function to generate files with random student data
void generateFiles() {
    vector<int> numRecords = {1000, 10000, 100000, 1000000, 10000000};
    string baseFilename = "studentai";
    string extension = ".txt";

    for (int numRecords : numRecords) {
        string filename = baseFilename + to_string(numRecords) + extension;
        ofstream outputFile(filename);
        if (!outputFile.is_open()) {
            cerr << "Unable to create file: " << filename << endl;
            continue;
        }

        // Header line
        outputFile << left << setw(25) << "Vardas" << setw(25) << "Pavarde";
        for (int i = 1; i <= 15; ++i) {
            outputFile << left << setw(10) << "ND" + to_string(i);
        }
        outputFile << left << setw(10) << "Egz." << endl;

        // Generate random student data
        for (int i = 1; i <= numRecords; ++i) {
            Student student;
            student.firstName = "Vardas" + to_string(i);
            student.lastName = "Pavarde" + to_string(i);
            generateGrades(student, 15); // Generate 15 random grades
            student.finalExamGrade = rand() % 10 + 1; // Generate random final exam grade

            // Write student data to file
            outputFile << left << setw(25) << student.firstName << setw(25) << student.lastName;
            for (int grade : student.grades) {
                outputFile << left << setw(10) << grade;
            }
            outputFile << left << setw(10) << student.finalExamGrade << endl;
        }

        outputFile.close();
        cout << "File generated: " << filename << endl;
    }
}


// Function to sort students into two categories and write to separate files
void sortAndWriteToFile(const string& inputFilename) {
    vector<Student> students;
    readFromFile(inputFilename, students);

    vector<Student> vargsiukai, kietiakiai;

    // Categorize students
    for (const auto& student : students) {
        double finalGrade = calculateAverage(student) * 0.4 + student.finalExamGrade * 0.6;
        if (finalGrade < 5.0) {
            vargsiukai.push_back(student);
        } else {
            kietiakiai.push_back(student);
        }
    }

    // Write categorized students to separate files
    writeCategorizedStudents(vargsiukai, "vargsiukai_" + inputFilename);
    writeCategorizedStudents(kietiakiai, "kietiakiai_" + inputFilename);

    cout << "Categorized students written to files." << endl;
}

void generatingFinal() {
    cout << "1 - Generuoti failus" << endl;
    string choice;
    cin >> choice;

    if (choice == "1") {
        // Generate files with random student data
        // Replace this comment with the logic to generate files
    } else {
        cout << "Neteisinga įvestis. Programa baigta." << endl;
        return; // Return void in this case
    }
}
