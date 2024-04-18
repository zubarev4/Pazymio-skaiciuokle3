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

## v1.5
### Sukurtos dvi: bazinė (abstrakti) klasė - Zmogus, skirta bendrai aprašyti žmogų ir tuomet iš jos išvestinę (derived) klasę - Student. 

```cpp
class Zmogus {
protected:
    string firstName;
    string lastName;

    Zmogus() = default;
    Zmogus(const string& fName, const string& lName) : firstName(fName), lastName(lName) {}
    virtual ~Zmogus() {}
public:
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
........................ visa kita taip pat kaip ir v1.2 ..............................................
```
### Realizuota abstrakti klasė Zmogus, jos objektų kūrimas negalimas
<img src="https://github.com/zubarev4/Pazymio-skaiciuokle2/assets/147638474/9c299221-acdd-4d76-a62d-7a2eb7555786" alt="image" style="max-width:100px; width:50%; height:auto;">

_Zmogus::Zmogus() (declared at line 14 of "C:\ISI\1k\2s\Objektinis programavimas\v1.5\student.h") is inaccessible_

### Studento klasė išvestinė (derived) iš Žmogaus ir palaiko 1.2 versijoje realizuotą penkių metodų taisyklę. Visi realizuoti metodai Studento klasėje pilnai patikrinti (Visi konstruktoriai, kopijavimo, perkėlimo (move) metodai, destruktorius ir įvesties/išvesties metodai
<img src="https://github.com/zubarev4/Pazymio-skaiciuokle2/assets/147638474/73745f86-e7d6-4474-b6fc-e02ffb08ae5d" alt="image" style="max-width:80px; width:40%; height:auto;">

<img src="https://github.com/zubarev4/Pazymio-skaiciuokle2/assets/147638474/c791ed67-f479-4db4-8085-543ff651e90d" alt="image" style="max-width:80px; width:40%; height:auto;">

<img src="https://github.com/zubarev4/Pazymio-skaiciuokle2/assets/147638474/b83db06a-51a3-47d5-9ae6-101e64fc020c" alt="image" style="max-width:80px; width:40%; height:auto;">

