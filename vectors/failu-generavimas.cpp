#include "failu-generavimas.h"
#include "student.h"

void writeCategorizedStudents(const vector<Student>& students, const string& filename) { 
    ofstream outputFile(filename);
   
    if (!outputFile.is_open()) {
        cerr << "Neišeina atidaryti: " << filename << endl;
        return;
    }

    outputFile << left << setw(25) << "Vardas" << setw(25) << "Pavarde" << setw(15) << "Galutinis" << endl;
    outputFile << "------------------------------------------------------------------------" << endl;

    for (const auto& student : students) {
        outputFile << left << setw(25) << student.getFirstName() << setw(25) << student.getLastName() << fixed << setprecision(5) << setw(15) << student.getFinalGrade() << endl;
    }

    outputFile.close();
}

void generateFiles() {
    vector<int> numRecords = {1000, 10000, 100000, 1000000, 10000000};
    string extension = ".txt";

    for (int numRecords : numRecords) {
        string filename = to_string(numRecords) + extension;
        auto start = chrono::high_resolution_clock::now(); 
        ofstream outputFile(filename);
        if (!outputFile.is_open()) {
            cerr << "Neišeina sukurti: " << filename << endl;
            continue;
        }
        stringstream ss;
        ss << left << setw(25) << "Vardas" << setw(25) << "Pavarde";
        for (int i = 1; i <= 15; ++i) {
            ss << left << setw(10) << "ND" + to_string(i);
        }
        ss << left << setw(10) << "Egz." << endl;

        for (int i = 1; i <= numRecords; ++i) {
            Student student;
            student.setFirstName("Vardas" + to_string(i));
            student.setLastName("Pavarde" + to_string(i));
            ss << left << setw(25) << student.getFirstName() << setw(25) << student.getLastName();
        
            for (int j = 1; j <= 15; ++j) {
                int grade = rand() % 10 + 1; 
                ss << left << setw(10) << grade;
            }

            int finalExamGrade = rand() % 10 + 1; 
            ss << left << setw(10) << finalExamGrade << endl;
        }
        outputFile << ss.str();
        outputFile.close();
        auto stop = chrono::high_resolution_clock::now(); 
        chrono::duration<double> time = stop - start;
        if (outputFile) {
            cout << "Failai sugeneruoti: " << filename << endl;
        } else {
            cerr << "Klauda rašant: " << filename << endl;
        }
     cout << "Failo " << filename << " kūrimo laikas: " << time.count() << " sekundės " << endl;
     cout << endl;

    }
}

void sortAndWriteToFile(const string& inputFilename) {
    vector<Student> students;
    readFromFile(inputFilename, students);

    auto start = chrono::high_resolution_clock::now();

    for (auto& student : students) {
       double average = calculateAverage(student);
        student.setFinalGrade(average * 0.4 + student.getFinalExamGrade() * 0.6);
    }

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.getFinalGrade() > b.getFinalGrade();
    });

    auto stop1 = chrono::high_resolution_clock::now();
    chrono::duration<double> time1 = stop1 - start;
    cout << "Studentų rūšiavimo didėjimo tvarka " << inputFilename << " laikas: " << time1.count() << " sekundės " << endl;

     vector<Student> vargsiukai;
    auto partitionPoint = std::remove_if(students.begin(), students.end(), [&](const Student& student) {
         if (student.getFinalGrade() < 5.0) {
            vargsiukai.push_back(student);
            return true; 
        }
        return false;
    });
    students.erase(partitionPoint, students.end()); 
    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double> time = stop - start;

    cout << "Studentų skirstymas " << inputFilename << " į kietekus ir vargšiukus laikas: " << time.count() << " sekundės " << endl;
    cout << endl;

    auto start3 = chrono::high_resolution_clock::now(); 
    
    writeCategorizedStudents(vargsiukai, "vargsiukai_" + inputFilename);
    writeCategorizedStudents(students, "kietiakai_" + inputFilename);
    
    auto stop3 = chrono::high_resolution_clock::now(); 
    chrono::duration<double> duration3 = stop3 - start3;    
    cout << "Studentų išvedimo į vargšiukus ir kietekus laikas: "  << duration3.count() << " sekundės " << endl;
}

void generatingFinal() {
        auto start = chrono::high_resolution_clock::now(); 
        generateFiles();
        auto stop = chrono::high_resolution_clock::now(); 
        auto duration = chrono::duration_cast<chrono::seconds>(stop - start);
        cout << endl;
        cout << "Generuoti failus veiksmo veikimo laikas : " << duration.count() << " sekundės " << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
}

