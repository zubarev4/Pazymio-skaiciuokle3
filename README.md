# Programos veikimas: 
1. Paleidus programą, vartotojui pateikiami pasirinkimai: 1 - Jei norite generuoti failus 2 - Jei norite nuskaityti iš failo 3 - Jei norite vesti duomenis 4 - Jei norite išeiti
2. Pasirinkus 1: Vartotojui sugeneruojami 5 failai su skirtingais studentų skaičiais: 1 000, 10 000, 100 000, 1 000 000, 10 000 000. Taip pat pateikiamas laikas, per kurį studentų failai buvo sukurti, nuskaityti, surūšiuoti ir išvesti į  failus.
3. Pasirinkus 2: paklausiama iš kurio iš 4-ių failų norima nuskaityti. Apskaičiavus rezultatus vartotojo paklausiama kaip jis norėtų rūšiuoti duomenis: vardas, pavardė, galutinis pagal vidurkį arba galutinis pagal medianą. 
4. Pasirinkus 3:  paklausiama ar nori įvesti studento vardą bei pavardę ranka ar generuoti.Paklausiama kokiu būdu norima įvesti pažymius (įrašyti ranka arba generuoti atsitiktinai). Įrašius visus pažymius ir egzamino įvertinimą, vartotojui leidžiama pasirinkti pridėti dar studentų arba baigti žmonių įvedimą. Pasirinkus vartotojui yra atspausdinamas sąrašas su visais studentais ir jų galutiniais vidurkiais ir medianomis.

### Instaliavimo instrukcija
- Jeigu naudojate „Visual Studio Code“, rekomenduojama įdiegti šiuos išplėtinius: "C/C++ Extension Pack", "C/C++ Runner", "Code Runner".
- Taip pat parsisiuskite https://www.msys2.org/ ir nusistatykite bin folderį į PATH per environmental variables.
- Meniu juostos pasirinkite "Terminal“ -> "Select Default Profile“. Šiame lange turėtumete rasti bash(MSYS2) C:\msys64\usr\bin\bash.exe. Naudodami cd komandą, pateikite klonuoto saugyklos kelią: cd jūsų/direktorijos/kelias/ Pavyzdžiui, cd /c/ISI/1k/2s/Objektinis\ programavimas/v1.0
- Norėdami paleisti programą, turite ją sukompiliuoti naudodami „Makefile“ failą, kuris yra saugykloje. Programos terminale rašykite: make ; ./program_pavadinimas

## v1.2
### Rule of five
https://en.cppreference.com/w/cpp/language/rule_of_three

- copy constructor,
```cpp
Student(const Student& other)
    : firstName(other.firstName), lastName(other.lastName), grades(other.grades), finalExamGrade(other.finalExamGrade), median(other.median), average(other.average), fin_median(other.fin_median), fin_average(other.fin_average), finalGrade(other.finalGrade) {}

 // Test copy constructor in tests() located in vektoriai.cpp
    Student s3 = s2;
    assert(s3.getFirstName() == "Alice");
    assert(s3.getLastName() == "Brown");
    assert(s3.getGrades().empty());
    assert(s3.getFinalExamGrade() == 0);
    assert(s3.getMedian() == 0.0);
    assert(s3.getAverage() == 0.0);
    assert(s3.getFinalMedian() == 0.0);
    assert(s3.getFinalAverage() == 0.0);
    assert(s3.getFinalGrade() == 0.0);
```
  
- copy assignment operator,
```cpp
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
```
- move constructor,
```cpp
Student(Student&& other) noexcept
    : firstName(std::move(other.firstName)), lastName(std::move(other.lastName)), grades(std::move(other.grades)), finalExamGrade(std::move(other.finalExamGrade)), median(std::move(other.median)), average(std::move(other.average)), fin_median(std::move(other.fin_median)), fin_average(std::move(other.fin_average)), finalGrade(std::move(other.finalGrade)) {}

// Test move constructor in tests() located in vektoriai.cpp
    Student s4 = std::move(s3);
    assert(s4.getFirstName() == "Alice");
    assert(s4.getLastName() == "Brown");
    assert(s4.getGrades().empty());
    assert(s4.getFinalExamGrade() == 0);
    assert(s4.getMedian() == 0.0);
    assert(s4.getAverage() == 0.0);
    assert(s4.getFinalMedian() == 0.0);
    assert(s4.getFinalAverage() == 0.0);
    assert(s4.getFinalGrade() == 0.0);
    assert(s3.getFirstName() == "");
    assert(s3.getLastName() == "");
    assert(s3.getGrades().empty());
    assert(s3.getFinalExamGrade() == 0);
    assert(s3.getMedian() == 0.0);
    assert(s3.getAverage() == 0.0);
    assert(s3.getFinalMedian() == 0.0);
    assert(s3.getFinalAverage() == 0.0);
    assert(s3.getFinalGrade() == 0.0);
```

- move assignment operator,
```cpp
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
```
- destructor
```cpp
  ~Student() {}
```

### Įvesties/išvesties operatoriai

#### Input
Įvesties nustatymams naudojami setteriai. Kaip pavyzdį naudosiu setVardas.
Metodas setVardas nustato mokinio vardą.
Gavęs vardą, jis jį išsaugo privačiame nario kintamajame vardas. Pvz:
cin >> vardas;
naujas_studentas.setVardas(vardas);

_Rankinis įvedimas_

Vartotojai pateikia studento vardą per įvestį. Metodas setVardas nustato studento vardą ir išsaugo jį privačiame nario kintamajame vardas.

_Automatinis įvedimas_

Programa sugeneruoja mokinio duomenis. Metodas gali priimti vardą ir saugoti jį privačiame nario kintamajame vardas.

_Įvestis iš failo_

Metodas gali nuskaityti mokinio vardą iš failo ir tada jį išsaugoti privačiuose nario kintamuosiuose.

```cpp
// Input Operator
friend std::istream& operator>>(std::istream& i, Student& student) {
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
    
//  final median
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
```
Įvesties operatorių testuoju readFromFile metode vektoriai.cpp: 

![image](https://github.com/zubarev4/Pazymio-skaiciuokle2/assets/147638474/e32d9a6b-ad6d-4af9-80e8-bd58ce36cdef)

![image](https://github.com/zubarev4/Pazymio-skaiciuokle2/assets/147638474/27110d58-d0b5-440a-9182-8d7c7d8dc5d3)


#### Output
```cpp
// Output Operator
friend std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << setw(10) << student.firstName << setw(20) << student.lastName; 
    os << fixed << setw(25) << setprecision(2) << student.fin_average; 
    os << fixed << setw(25) << setprecision(2) << student.fin_median << '\n'; 
    return os;
}
```
Išvesties operatorių testuoju printResults metode vektoriai.cpp: 

![image](https://github.com/zubarev4/Pazymio-skaiciuokle2/assets/147638474/6b5df0f0-017d-4cee-81f0-a2c15e68392b)

![image](https://github.com/zubarev4/Pazymio-skaiciuokle2/assets/147638474/94980ada-c60a-465d-a5e9-5e072ea51387)

