#ifndef VEKTORIAI_H
#define VEKTORIAI_H


#include "vector.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <numeric>
#include <chrono>
#include <cassert>


using namespace std;

class Student;
bool isValidName(const string& name);
bool isValidGrade(const string& grade);
double calculateAverage(const Student& student);
double calculateMedian(const Student& student);
void randomGradeGenerator(int number, Student& student);
void generateNames(Student& student);
void readFromFile(const string& filename, Vector<Student>& students);
void tests();
void checkVector();
void vectorVsVector();

#endif 