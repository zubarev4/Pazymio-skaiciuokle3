#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "vector.h"
#include "student.h" 


TEST_CASE(" Funkcijos testas", "[Vector]") {
    SECTION("push_back testas") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        REQUIRE(v.size() == 3);
        REQUIRE(v[0] == 1);
        REQUIRE(v[1] == 2);
        REQUIRE(v[2] == 3);
    }

    SECTION("pop_back testas") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.pop_back();
        REQUIRE(v.size() == 2);
        REQUIRE(v[0] == 1);
        REQUIRE(v[1] == 2);
    }

    SECTION("shrink_to_fit testas") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.shrink_to_fit();
        REQUIRE(v.size() == 3);
        REQUIRE(v[0] == 1);
        REQUIRE(v[1] == 2);
        REQUIRE(v[2] == 3);
    }

    SECTION("erase testas") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.erase(v.begin() + 1);
        REQUIRE(v.size() == 2);
        REQUIRE(v[0] == 1);
        REQUIRE(v[1] == 3);
    }

    SECTION("resize testas") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.resize(2);
        REQUIRE(v.size() == 2);
        REQUIRE(v[0] == 1);
        REQUIRE(v[1] == 2);
    }

    SECTION("clear testas") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.clear();
        REQUIRE(v.size() == 0);
    }

    SECTION("insert testas") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        auto it = v.insert(v.begin(), 2, 0);
        REQUIRE(it == v.begin());
        REQUIRE(v == Vector<int>({0, 0, 1, 2, 3}));
}

    SECTION("capacity testas") {
        Vector<int> v;
        REQUIRE(static_cast<size_t>(0) == v.capacity());
        Vector<int> v3;
        REQUIRE(static_cast<size_t>(0) == v3.capacity());
        v3.push_back(1);
        REQUIRE(static_cast<size_t>(1) == v3.capacity());
        v3.push_back(2);
        REQUIRE(static_cast<size_t>(2) == v3.capacity());
        v3.push_back(3);
        REQUIRE(static_cast<size_t>(4) == v3.capacity());
        v3.push_back(4);
        v3.push_back(5);
        REQUIRE(static_cast<size_t>(8) == v3.capacity());
        Vector<int> v4;
        v4.reserve(10);
        REQUIRE(static_cast<size_t>(10) == v4.capacity());
    }

    SECTION("front testas") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        REQUIRE(v.front() == 1);
        v.front() = 10;
        REQUIRE(v.front() == 10);
        REQUIRE(v[0] == 10);
        REQUIRE(v[1] == 2);
        REQUIRE(v[2] == 3);
    }

    SECTION("back testas") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        REQUIRE(v.back() == 3);
        v.back() = 10;
        REQUIRE(v.back() == 10);
        REQUIRE(v[v.size() - 1] == 10);
        REQUIRE(v[0] == 1);
        REQUIRE(v[1] == 2);
        REQUIRE(v[2] == 10);
    }

    SECTION("begin testas") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        auto it = v.begin();
        REQUIRE(*it == 1);
        *it = 10;
        REQUIRE(*it == 10);
        REQUIRE(v[0] == 10);
        REQUIRE(v[1] == 2);
        REQUIRE(v[2] == 3);
    }

    SECTION("end testas") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        auto it = v.end();
        it--;
        REQUIRE(*it == 3);
        *it = 10;
        REQUIRE(*it == 10);
        REQUIRE(v[0] == 1);
        REQUIRE(v[1] == 2);
        REQUIRE(v[2] == 10);
    }

    SECTION("at testas") {
        Vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        REQUIRE(v.at(0) == 1);
        v.at(0) = 10;
        REQUIRE(v.at(0) == 10);
        REQUIRE(v[0] == 10);
        REQUIRE(v[1] == 2);
        REQUIRE(v[2] == 3);
    }

    SECTION("empty testas") {
        Vector<int> v;
        REQUIRE(v.empty());
        v.push_back(1);
        REQUIRE(!v.empty());
    }
    
}
TEST_CASE("Constructor and Property Tests", "[Vector]") {
    // Default Constructor Test
    SECTION("Default Constructor testas") {
        Vector<int> v;
        Vector<Student> v2;
        REQUIRE(v2.begin() == v2.end());
        REQUIRE(v.begin() == v.end());
    }

    // Copy Constructor Test
    SECTION("Copy Constructor veikia") {
        Vector<int> v1{1, 2, 3};
        Vector<int> v2(v1);
        REQUIRE(std::distance(v2.begin(), v2.end()) == 3);
        auto it = v2.begin();
        REQUIRE(*it++ == 1);
        REQUIRE(*it++ == 2);
        REQUIRE(*it++ == 3);

        Vector<Student> vs1;
        Student s1("John", "Doe", Vector<int>{5, 4, 3}, 5, 4.0, 4.0);
        vs1.push_back(s1);
        Vector<Student> vs2(vs1);
        REQUIRE(std::distance(vs2.begin(), vs2.end()) == 1);
        REQUIRE(vs2.begin()->getFirstName() == "John");
        REQUIRE(vs2.begin()->getLastName() == "Doe");
    }

    // Move Constructor Test
    SECTION("Move Constructor veikia") {
        Vector<int> v1{1, 2, 3};
        Vector<int> v2(std::move(v1));
        REQUIRE(std::distance(v2.begin(), v2.end()) == 3);
        auto it = v2.begin();
        REQUIRE(*it++ == 1);
        REQUIRE(*it++ == 2);
        REQUIRE(*it++ == 3);
        REQUIRE(v1.begin() == v1.end());

        Vector<Student> vs1;
        Student s1("John", "Doe", Vector<int>{5, 4, 3}, 5, 4.0, 4.0);
        vs1.push_back(s1);
        Vector<Student> vs2(std::move(vs1));
        REQUIRE(std::distance(vs2.begin(), vs2.end()) == 1);
        REQUIRE(vs2.begin()->getFirstName() == "John");
        REQUIRE(vs2.begin()->getLastName() == "Doe");
        REQUIRE(vs1.begin() == vs1.end());

    }

    // Copy Assignment Operator Test
    SECTION("Copy Assignment Operator veikia") {
        Vector<int> v1{1, 2, 3};
        Vector<int> v2;
        v2 = v1;
        REQUIRE(std::distance(v2.begin(), v2.end()) == 3);
        auto it = v2.begin();
        REQUIRE(*it++ == 1);
        REQUIRE(*it++ == 2);
        REQUIRE(*it++ == 3);

        Vector<Student> vs1;
        Student s1("John", "Doe", Vector<int>{5, 4, 3}, 5, 4.0, 4.0);
        vs1.push_back(s1);
        Vector<Student> vs2;
        vs2 = vs1;
        REQUIRE(std::distance(vs2.begin(), vs2.end()) == 1);
        REQUIRE(vs2.begin()->getFirstName() == "John");
        REQUIRE(vs2.begin()->getLastName() == "Doe");
    }

    // Move Assignment Operator Test
    SECTION("Move Assignment Operator veikia") {
        Vector<int> v1{1, 2, 3};
        Vector<int> v2;
        v2 = std::move(v1);
        REQUIRE(std::distance(v2.begin(), v2.end()) == 3);
        auto it = v2.begin();
        REQUIRE(*it++ == 1);
        REQUIRE(*it++ == 2);
        REQUIRE(*it++ == 3);
        REQUIRE(v1.begin() == v1.end());

        Vector<Student> vs1;
        Student s1("John", "Doe", Vector<int>{5, 4, 3}, 5, 4.0, 4.0);
        vs1.push_back(s1);
        Vector<Student> vs2;
        vs2 = std::move(vs1);
        REQUIRE(std::distance(vs2.begin(), vs2.end()) == 1);
        REQUIRE(vs2.begin()->getFirstName() == "John");
        REQUIRE(vs2.begin()->getLastName() == "Doe");
        REQUIRE(vs1.begin() == vs1.end());   
    }
}
