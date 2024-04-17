#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
using namespace std;

class Student {
private:
    string firstName;
    string lastName;
    vector<int> grades;
    int finalExamGrade;
    double median, average;
    double fin_median, fin_average, finalGrade;

public:
    Student() : finalExamGrade(0), median(0.0), average(0.0), fin_median(0.0), fin_average(0.0), finalGrade(0.0) {}
    Student(const string& fName, const string& lName) : firstName(fName), lastName(lName), finalExamGrade(0), median(0.0), average(0.0), fin_median(0.0), fin_average(0.0), finalGrade(0.0) {}

   // Destructor
    ~Student() {}

    // Copy Constructor
    Student(const Student& other)
    : firstName(other.firstName), lastName(other.lastName), grades(other.grades), finalExamGrade(other.finalExamGrade), median(other.median), average(other.average), fin_median(other.fin_median), fin_average(other.fin_average), finalGrade(other.finalGrade) {}

    // Move Constructor
    Student(Student&& other) noexcept
    : firstName(std::move(other.firstName)), lastName(std::move(other.lastName)), grades(std::move(other.grades)), finalExamGrade(std::move(other.finalExamGrade)), median(std::move(other.median)), average(std::move(other.average)), fin_median(std::move(other.fin_median)), fin_average(std::move(other.fin_average)), finalGrade(std::move(other.finalGrade)) {}

    // Copy Assignment Operator
    Student& operator=(const Student& other) {
        if (this != &other) { // self-assignment check
            firstName = other.firstName;
            lastName = other.lastName;
            grades = other.grades;
            finalExamGrade = other.finalExamGrade;
            median = other.median;
            average = other.average;
            fin_median = other.fin_median;
            fin_average = other.fin_average;
            finalGrade = other.finalGrade;
        }
        return *this;
    }   

    // Move Assignment Operator
    Student& operator=(Student&& other) noexcept {
        if (this != &other) { 
            firstName = std::move(other.firstName);
            lastName = std::move(other.lastName);
            grades = std::move(other.grades);
            finalExamGrade = std::move(other.finalExamGrade);
            median = std::move(other.median);
            average = std::move(other.average);
            fin_median = std::move(other.fin_median);
            fin_average = std::move(other.fin_average);
            finalGrade = std::move(other.finalGrade);
        }
        return *this;
    }

    // Input Operator
friend std::istream& operator>>(std::istream& i, Student& student) {
    i >> student.firstName >> student.lastName;
    int numGrades;
    i >> numGrades;
    student.grades.resize(numGrades);
    for (int j = 0; j < numGrades; ++j) {
        i >> student.grades[j];
    }
    i >> student.finalExamGrade;
    i >> student.median >> student.average;
    i >> student.fin_median >> student.fin_average >> student.finalGrade;
    return i;
}

// Output Operator
friend std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "First Name: " << student.firstName << "\n"
       << "Last Name: " << student.lastName << "\n";
    os << "Grades: ";
    for (int grade : student.grades) {
        os << grade << " ";
    }
    os << "\nFinal Exam Grade: " << student.finalExamGrade << "\n"
       << "Median: " << student.median << "\n"
       << "Average: " << student.average << "\n"
       << "Final Grade: " << student.finalGrade << "\n";
    return os;
}

    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    const vector<int>& getGrades() const { return grades; }
    int getFinalExamGrade() const { return finalExamGrade; }
    double getMedian() const { return median; }
    double getAverage() const { return average; }
    double getFinalMedian() const { return fin_median; }
    double getFinalAverage() const { return fin_average; }
    double getFinalGrade() const { return finalGrade; }

    
    void setFirstName(const string& fName) { firstName = fName; }
    void setLastName(const string& lName) { lastName = lName; }
    void setGrades(const vector<int>& newGrades) { grades = newGrades; }
    void setFinalExamGrade(int examGrade) { finalExamGrade = examGrade; }
    void setMedian(double medianValue) { median = medianValue; }
    void setAverage(double averageValue) { average = averageValue; }
    void setFinalMedian(double finalMedian) { fin_median = finalMedian; }
    void setFinalAverage(double finalAverage) { fin_average = finalAverage; }
    void setFinalGrade(double finalGradeValue) { finalGrade = finalGradeValue; }
};

#endif
