#ifndef FAILU_GENERAVIMAS_H
#define FAILU_GENERAVIMAS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "vektoriai.h" // Include vektoriai.h for the Student struct

using namespace std;

void writeCategorizedStudents(const vector<Student>& students, const string& filename);
void generateGrades(Student& student, int numGrades);
void generateFiles();
void sortAndWriteToFile(const string& inputFilename);

#endif
