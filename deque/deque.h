#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <random>
#include <sstream>
#include <limits>
#include <numeric>
#include <chrono>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    deque<int> grades;
    int finalExamGrade;
    double median, average;
    double fin_median, fin_average;
};

bool isValidName(const string& name);
bool isValidGrade(const string& grade);
double calculateAverage(const Student& student);
double calculateMedian(const Student& student);
void randomGradeGenerator(int number, Student& student);
int randomInt(int min, int max);
void generateNames(Student& student);
void readFromFile(const string& filename, deque<Student>& students);
bool sortByAverage(const Student& studentA, const Student& studentB);
bool sortByMedian(const Student& studentA, const Student& studentB);
void sortStudents(deque<Student>& students, char option);
void printResults(const deque<Student>& students, char sortingOption, const string& outputFilename);

#endif 