# Programos veikimas: 
1. Paleidus programą, vartotojui pateikiami pasirinkimai: 1 - Jei norite generuoti failus 2 - Jei norite nuskaityti iš failo 3 - Jei norite vesti duomenis 4 - Jei norite išeiti
2. Pasirinkus 1: Vartotojui sugeneruojami 5 failai su skirtingais studentų skaičiais: 1 000, 10 000, 100 000, 1 000 000, 10 000 000. Taip pat pateikiamas laikas, per kurį studentų failai buvo sukurti, nuskaityti, surūšiuoti ir išvesti į  failus.
3. Pasirinkus 2: paklausiama iš kurio iš 4-ių failų norima nuskaityti. Apskaičiavus rezultatus vartotojo paklausiama kaip jis norėtų rūšiuoti duomenis: vardas, pavardė, galutinis pagal vidurkį arba galutinis pagal medianą. 
4. Pasirinkus 3:  paklausiama ar nori įvesti studento vardą bei pavardę ranka ar generuoti.Paklausiama kokiu būdu norima įvesti pažymius (įrašyti ranka arba generuoti atsitiktinai). Įrašius visus pažymius ir egzamino įvertinimą, vartotojui leidžiama pasirinkti pridėti dar studentų arba baigti žmonių įvedimą. Pasirinkus vartotojui yra atspausdinamas sąrašas su visais studentais ir jų galutiniais vidurkiais ir medianomis.

### Naujos repozitorijos sukūrimas
- git clone --mirror https://github.com/zubarev4/Pazymio-skaiciuokle1.git
- git clone --bare C:\Users\Pazymio-skaiciuokle1.git Pazymio-skaiciuokle2
- git branch -a
- git remote set-url origin https://github.com/zubarev4/Pazymio-skaiciuokle2.git
- git push --mirror

### Instaliavimo instrukcija
- Jeigu naudojate „Visual Studio Code“, rekomenduojama įdiegti šiuos išplėtinius: "C/C++ Extension Pack", "C/C++ Runner", "Code Runner".
- Taip pat parsisiuskite https://www.msys2.org/ ir nusistatykite bin folderį į PATH per environmental variables.
- Meniu juostos pasirinkite "Terminal“ -> "Select Default Profile“. Šiame lange turėtumete rasti bash(MSYS2) C:\msys64\usr\bin\bash.exe. Naudodami cd komandą, pateikite klonuoto saugyklos kelią: cd jūsų/direktorijos/kelias/ Pavyzdžiui, cd /c/ISI/1k/2s/Objektinis\ programavimas/v1.0
- Norėdami paleisti programą, turite ją sukompiliuoti naudodami „Makefile“ failą, kuris yra saugykloje. Programos terminale rašykite: make ; ./program_pavadinimas

## v1.2
### Rule of five
https://en.cppreference.com/w/cpp/language/rule_of_three

- copy constructor,
  
Student(const Student& other)
    : firstName(other.firstName), lastName(other.lastName), grades(other.grades), finalExamGrade(other.finalExamGrade), median(other.median), average(other.average), fin_median(other.fin_median), fin_average(other.fin_average), finalGrade(other.finalGrade) {}
  
- copy assignment operator,

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

- move constructor,

Student(Student&& other) noexcept
    : firstName(std::move(other.firstName)), lastName(std::move(other.lastName)), grades(std::move(other.grades)), finalExamGrade(std::move(other.finalExamGrade)), median(std::move(other.median)), average(std::move(other.average)), fin_median(std::move(other.fin_median)), fin_average(std::move(other.fin_average)), finalGrade(std::move(other.finalGrade)) {}


- move assignment operator,

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

- destructor

  ~Student() {}


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

#### Output

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
