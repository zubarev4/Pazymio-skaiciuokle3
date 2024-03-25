#ifndef FAILU_GENERAVIMAS_DEQUE_H
#define FAILU_GENERAVIMAS_DEQUE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <string>
#include <ctime>
#include <cstdlib>
#include "deque.h"

using namespace std;

void writeCategorizedStudents(const deque<Student>& students, const string& filename);
void generateFiles();
void sortAndWriteToFile(const string& inputFilename);
void generatingFinal();

#endif
