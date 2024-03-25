#ifndef VEKTORIAI_H
#define VEKTORIAI_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <numeric>
#include <chrono>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    vector<int> grades;
    int finalExamGrade;
    double median, average;
    double fin_median, fin_average;
};

bool isValidName(const string& name);
bool isValidGrade(const string& grade);
double calculateAverage(const Student& student);
double calculateMedian(const Student& student);
void randomGradeGenerator(int number, Student& student);
void generateNames(Student& student);
void readFromFile(const string& filename, vector<Student>& students);
bool sortByAverage(const Student& studentA, const Student& studentB);
bool sortByMedian(const Student& studentA, const Student& studentB);
void sortStudents(vector<Student>& students, char option);
void printResults(const vector<Student>& students, char sortingOption, const string& outputFilename);

#endif 