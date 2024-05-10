#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "student.h" 

TEST_CASE("Student Constructor and Property Tests", "[Student]") {
    // Default Constructor Test
    SECTION("Default Constructor testas") {
        Student student;
        REQUIRE(student.getFirstName().empty());
        REQUIRE(student.getLastName().empty());
        REQUIRE(student.getGrades().empty());
        REQUIRE(student.getFinalExamGrade() == 0);
        REQUIRE(student.getMedian() == 0.0);
        REQUIRE(student.getAverage() == 0.0);
        REQUIRE(student.getFinalMedian() == 0.0);
        REQUIRE(student.getFinalAverage() == 0.0);
        REQUIRE(student.getFinalGrade() == 0.0);
    }

    // Copy Constructor Test
    SECTION("Copy Constructor veikia") {
        Student original("John", "Doe", {10, 9, 8}, 7, 9.5, 9.0);
        Student copyConstructed(original);

        REQUIRE(copyConstructed.getFirstName() == original.getFirstName());
        REQUIRE(copyConstructed.getLastName() == original.getLastName());
        REQUIRE(copyConstructed.getGrades() == original.getGrades());
        REQUIRE(copyConstructed.getFinalExamGrade() == original.getFinalExamGrade());
        REQUIRE(copyConstructed.getMedian() == original.getMedian());
        REQUIRE(copyConstructed.getAverage() == original.getAverage());
        REQUIRE(copyConstructed.getFinalMedian() == original.getFinalMedian());
        REQUIRE(copyConstructed.getFinalAverage() == original.getFinalAverage());
        REQUIRE(copyConstructed.getFinalGrade() == original.getFinalGrade());
    }

    // Move Constructor Test
    SECTION("Move Constructor veikia") {
        Student original("John", "Doe", {10, 9, 8}, 7, 9.5, 9.0);
        Student movedTo(std::move(original));

        REQUIRE(movedTo.getFirstName() == "John");
        REQUIRE(movedTo.getLastName() == "Doe");
        REQUIRE(movedTo.getGrades() == vector<int>{10, 9, 8});
        REQUIRE(movedTo.getFinalExamGrade() == 7);
        REQUIRE(original.getFirstName().empty()); 
        REQUIRE(original.getLastName().empty());   
        REQUIRE(original.getGrades().empty());     
    }

    // Copy Assignment Operator Test
    SECTION("Copy Assignment Operator veikia") {
        Student original("John", "Doe", {10, 9, 8}, 7, 9.5, 9.0);
        Student assigned;
        assigned = original;

        REQUIRE(assigned.getFirstName() == original.getFirstName());
        REQUIRE(assigned.getLastName() == original.getLastName());
        REQUIRE(assigned.getGrades() == original.getGrades());
        REQUIRE(assigned.getFinalExamGrade() == original.getFinalExamGrade());
        REQUIRE(assigned.getMedian() == original.getMedian());
        REQUIRE(assigned.getAverage() == original.getAverage());
        REQUIRE(assigned.getFinalMedian() == original.getFinalMedian());
        REQUIRE(assigned.getFinalAverage() == original.getFinalAverage());
        REQUIRE(assigned.getFinalGrade() == original.getFinalGrade());
    }

    // Move Assignment Operator Test
    SECTION("Move Assignment Operator veikia") {
        Student original("John", "Doe", {10, 9, 8}, 7, 9.5, 9.0);
        Student movedTo;
        movedTo = std::move(original);

        REQUIRE(movedTo.getFirstName() == "John");
        REQUIRE(movedTo.getLastName() == "Doe");
        REQUIRE(movedTo.getGrades() == vector<int>{10, 9, 8});
        REQUIRE(movedTo.getFinalExamGrade() == 7);
        REQUIRE(original.getFirstName().empty());  
        REQUIRE(original.getLastName().empty());  
        REQUIRE(original.getGrades().empty());     
    }
}
