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
    auto duration = chrono::duration_cast<chrono::seconds>(stop - start);
    //cout << "Surūšiotus studentus rasite: " << filename << endl;
    cout << "Studentų išvedimo į " << filename << " laikas: " << duration.count() << " sekundės " << endl;
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
        auto duration = chrono::duration_cast<chrono::seconds>(stop - start);
        if (outputFile) {
            cout << "Failai sugeneruoti: " << filename << endl;
        } else {
            cerr << "Klauda rašant: " << filename << endl;
        }
     cout << "Failo " << filename << " kūrimo laikas: " << duration.count() << " sekundės " << endl;
     cout << endl;

    }
}


void sortAndWriteToFile(const string& inputFilename) {
    vector<Student> students;
    readFromFile(inputFilename, students);

    vector<Student> vargsiukai, kietiakai;
    auto start = chrono::high_resolution_clock::now();
    auto stop = chrono::high_resolution_clock::now();
    auto stop2 = chrono::high_resolution_clock::now();

    for (const auto& student : students) {
        double finalGrade = calculateAverage(student) * 0.4 + student.finalExamGrade * 0.6;
        if (finalGrade < 5.0) {
            vargsiukai.push_back(student);
            stop = chrono::high_resolution_clock::now();
        } else {
            kietiakai.push_back(student);
            stop2 = chrono::high_resolution_clock::now();
        }
    }
    
    auto duration = chrono::duration_cast<chrono::seconds>(stop - start);
    cout << "Rūšiavimas į vargšiukus " << inputFilename << " laikas: " << duration.count() << " sekundės " << endl;
    auto duration2 = chrono::duration_cast<chrono::seconds>(stop2 - start);
    cout << "Rūšiavimas į kietekus " << inputFilename << " laikas: "<< duration2.count() << " sekundės " << endl;
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
        sortAndWriteToFile("1000.txt");
        sortAndWriteToFile("10000.txt");
        sortAndWriteToFile("100000.txt");
        sortAndWriteToFile("1000000.txt");
        sortAndWriteToFile("10000000.txt");
        auto stop = chrono::high_resolution_clock::now();
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
