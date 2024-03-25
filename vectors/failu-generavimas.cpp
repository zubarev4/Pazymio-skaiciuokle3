#include "failu-generavimas.h"

void writeCategorizedStudents(const vector<Student>& students, const string& filename) {
    auto start = chrono::high_resolution_clock::now(); 
    ofstream outputFile(filename);
   
    if (!outputFile.is_open()) {
        cerr << "Neišeina atidaryti: " << filename << endl;
        return;
    }

    outputFile << left << setw(25) << "Vardas" << setw(25) << "Pavarde" << setw(10) << "Galutinis" << endl;
    outputFile << "------------" << "------------" << "----------" << endl;

    for (const auto& student : students) {
        outputFile << student.firstName << " " << student.lastName << " " << student.finalExamGrade << endl;
    }

    outputFile.close();
    auto stop = chrono::high_resolution_clock::now(); 
    chrono::duration<double> time = stop - start;
    cout << "Studentų išvedimo į " << filename << " laikas: " << time.count() << " sekundės " << endl;
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

        outputFile << left << setw(25) << "Vardas" << setw(25) << "Pavarde";
        for (int i = 1; i <= 15; ++i) {
            outputFile << left << setw(10) << "ND" + to_string(i);
        }
        outputFile << left << setw(10) << "Egz." << endl;

        for (int i = 1; i <= numRecords; ++i) {
            Student student;
            student.firstName = "Vardas" + to_string(i);
            student.lastName = "Pavarde" + to_string(i);
            outputFile << left << setw(25) << student.firstName << setw(25) << student.lastName;
        
            for (int j = 1; j <= 15; ++j) {
                int grade = rand() % 10 + 1; 
                outputFile << left << setw(10) << grade;
            }

            int finalExamGrade = rand() % 10 + 1; 
            outputFile << left << setw(10) << finalExamGrade << endl;
        }

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
        student.finalGrade = calculateAverage(student) * 0.4 + student.finalExamGrade * 0.6;
    }

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.finalGrade > b.finalGrade;
    });

    auto stop1 = chrono::high_resolution_clock::now();
    chrono::duration<double> time1 = stop1 - start;
    cout << "Studentų rūšiavimo didėjimo tvarka " << inputFilename << " laikas: " << time1.count() << " sekundės " << endl;

    vector<Student> vargsiukai, kietiakai;
    for (const auto& student : students) {
        if (student.finalGrade < 5.0 ) {
            vargsiukai.push_back(student);
        } else {
            kietiakai.push_back(student);
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double> time = stop - start;
    cout << "Studentų skirstymas " << inputFilename << " į kietekus ir vargšiukus laikas: " << time.count() << " sekundės " << endl;
    cout << endl;
    writeCategorizedStudents(vargsiukai, "vargsiukai_" + inputFilename);
    writeCategorizedStudents(kietiakai, "kietiakai_" + inputFilename);
}

void generatingFinal() {
    cout << "1 - Generuoti failus" << endl;
    string choice;

    cin >> choice;

    if (choice == "1") {
        auto start = chrono::high_resolution_clock::now(); 
        generateFiles();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        sortAndWriteToFile("1000.txt");
        sortAndWriteToFile("10000.txt");
        sortAndWriteToFile("100000.txt");
        sortAndWriteToFile("1000000.txt");
        sortAndWriteToFile("10000000.txt");
        auto stop = chrono::high_resolution_clock::now(); // Stop measuring time
        auto duration = chrono::duration_cast<chrono::seconds>(stop - start);
        cout << endl;
        cout << "Generuoti failus veiksmo veikimo laikas : " << duration.count() << " sekundės " << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    } else {
        cout << "Neteisinga įvestis." << endl;
         exit(EXIT_FAILURE);
    }
}
