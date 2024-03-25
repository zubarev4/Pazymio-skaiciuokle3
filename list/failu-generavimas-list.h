#ifndef FAILU_GENERAVIMAS_LIST_H
#define FAILU_GENERAVIMAS_LIST_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <string>
#include <ctime>
#include <cstdlib>
#include "list.h"

using namespace std;

void writeCategorizedStudents(const list<Student>& students, const string& filename);
void generateFiles();
void sortAndWriteToFile(const string& inputFilename);
void generatingFinal();

#endif
