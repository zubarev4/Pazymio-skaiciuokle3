#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include "vektoriai.h"
using namespace std;

class Zmogus {
protected:
    string firstName;
    string lastName;

    Zmogus() = default;
    Zmogus(const string& fName, const string& lName) : firstName(fName), lastName(lName) {}
    virtual void ppp() const = 0;
    
public:
    virtual ~Zmogus() {}
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    void setFirstName(const string& fName) { firstName = fName; }
    void setLastName(const string& lName) { lastName = lName; }
};

class Student : public Zmogus {
private:
    vector<int> grades;
    int finalExamGrade;
    double median, average;
    double fin_median, fin_average, finalGrade;

public:
    void ppp() const override {}
    Student() : finalExamGrade(0), median(0.0), average(0.0), fin_median(0.0), fin_average(0.0), finalGrade(0.0) {}
    Student(const string& fName, const string& lName) : Zmogus(fName,lName), finalExamGrade(0), median(0.0), average(0.0), fin_median(0.0), fin_average(0.0), finalGrade(0.0) {}

   // Destructor
    ~Student() { grades.clear(); firstName.clear(), lastName.clear(); }

    // Copy Constructor
    Student(const Student& other)
    : Zmogus(other.firstName, other.lastName), grades(other.grades), finalExamGrade(other.finalExamGrade), median(other.median), average(other.average), fin_median(other.fin_median), fin_average(other.fin_average), finalGrade(other.finalGrade) {}

    // Move Constructor
    Student(Student&& other) noexcept
    : Zmogus(move(other.firstName), move(other.lastName)), grades(move(other.grades)), finalExamGrade(move(other.finalExamGrade)), median(move(other.median)), average(move(other.average)), fin_median(move(other.fin_median)), fin_average(move(other.fin_average)), finalGrade(move(other.finalGrade)) {
    other.firstName.clear();
    other.lastName.clear();
    }

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
        
        other.firstName.clear();
        other.lastName.clear();
        }
        return *this;
    }

    // Input Operator
friend std::istream& operator>>(istream& i, Student& student) {
    string firstName, lastName;
    i >> firstName >> lastName;
    student.setFirstName(firstName); 
    student.setLastName(lastName);

    vector<int> grades;
    for (int j = 0; j < 15; ++j) {
        int grade;
        i >> grade;
        grades.push_back(grade);
    }
    student.setGrades(grades);

    i >> student.finalExamGrade;

    // final average
    double sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    double average = sum / grades.size();
    double finalAverage = average * 0.4 + student.finalExamGrade * 0.6;
    student.setFinalAverage(finalAverage);

    // final median
    sort(grades.begin(), grades.end());
    double finalMedian;
    if (grades.size() % 2 == 0) {
        finalMedian = (grades[grades.size() / 2 - 1] + grades[grades.size() / 2]) / 2.0;
    } else {
        finalMedian = grades[grades.size() / 2];
    }
    finalMedian = finalMedian * 0.4 + student.finalExamGrade * 0.6;
    student.setFinalMedian(finalMedian);

    return i;
}



// Output Operator
friend ostream& operator<<(ostream& os, const Student& student) {
    os << setw(10) << student.firstName << setw(20) << student.lastName; 
    os << fixed << setw(25) << setprecision(2) << student.fin_average; 
    os << fixed << setw(25) << setprecision(2) << student.fin_median << '\n'; 
    return os;
}



    const vector<int>& getGrades() const { return grades; }
    int getFinalExamGrade() const { return finalExamGrade; }
    double getMedian() const { return median; }
    double getAverage() const { return average; }
    double getFinalMedian() const { return fin_median; }
    double getFinalAverage() const { return fin_average; }
    double getFinalGrade() const { return finalGrade; }

    
    void setGrades(const vector<int>& newGrades) { grades = newGrades; }
    void setFinalExamGrade(int examGrade) { finalExamGrade = examGrade; }
    void setMedian(double medianValue) { median = medianValue; }
    void setAverage(double averageValue) { average = averageValue; }
    void setFinalMedian(double finalMedian) { fin_median = finalMedian; }
    void setFinalAverage(double finalAverage) { fin_average = finalAverage; }
    void setFinalGrade(double finalGradeValue) { finalGrade = finalGradeValue; }
};

#endif
