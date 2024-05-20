# Trečia užduotis: 
Šiame darbe (naudodamiesi paskaitos skaidrėmis, literatūra ir interneto šaltiniais) išplėskite mūsų kuriamos Vector klases funkcionalumą taip, kad ji būtų pilnavertė alternatyvą std::vector konteineriui, t.y. Jūsų klasė turi turėti visą funkcionalumą (Member types, Member functions, Non-member functions). Pratęskite (tuo pačiu ir patobulinkite) 1.5-os versijos Jūsų turimą programos realizaciją (versiją v3.0). Programą patobulinkite ir panaudokite savo sukurtą Vector klasę. Ištirkite savo programos veikimą su savo klasę Vector ir palyginkite rezultatus gautus su 1.5 versiją. Patobulinkite galutinį variantą taip, kad Jūsų programa butu įdiegiama naudojant jos įdiegimo failą. Be to rezultate naudotojui lengvai galima būtu ją pašalinti iš savo kompiuterio ją iš diegiant iš programų sąrašo.

### Programos veikimas: 
Paleidus programą, vartotojui pateikiami pasirinkimai: 9 - Jei norite išeiti 0 - Tikrinti Rule of Five 1 - Jei norite generuoti failus 2 - Jei norite nuskaityti iš failo 3 - Jei norite vesti duomenis 4 - Tikrinti Vector funkcijas 5 - std::vector VS Vector
Pasirinkus 0: Tikrinami ar Rule of Five veikia sklandžiai.
Pasirinkus 1: Vartotojui sugeneruojami 5 failai su skirtingais studentų skaičiais: 1 000, 10 000, 100 000, 1 000 000, 10 000 000. Taip pat pateikiamas laikas, per kurį studentų failai buvo sukurti, nuskaityti, surūšiuoti ir išvesti į failus.
Pasirinkus 2: paklausiama iš kurio iš 4-ių failų norima nuskaityti. Apskaičiavus rezultatus vartotojo paklausiama kaip jis norėtų rūšiuoti duomenis: vardas, pavardė, galutinis pagal vidurkį arba galutinis pagal medianą.
Pasirinkus 3: paklausiama ar nori įvesti studento vardą bei pavardę ranka ar generuoti.Paklausiama kokiu būdu norima įvesti pažymius (įrašyti ranka arba generuoti atsitiktinai). Įrašius visus pažymius ir egzamino įvertinimą, vartotojui leidžiama pasirinkti pridėti dar studentų arba baigti žmonių įvedimą. Pasirinkus vartotojui yra atspausdinamas sąrašas su visais studentais ir jų galutiniais vidurkiais ir medianomis.
Pasirinkus 4: Tikrinamos 5 funkcijos (pop_back, push_back, shrink_to_fit, begin, resize) naujo Vektoriaus.
Pasirinkus 5: Atliekama efektyvumo/spartos analizę: originalusis std::vector vs Vector.

### Naujos repozitorijos sukūrimas
- git clone --mirror https://github.com/zubarev4/Pazymio-skaiciuokle2.git
- cd Pazymio-skaiciuokle2.git
- git remote set-url origin https://github.com/zubarev4/Pazymio-skaiciuokle3.git
- git push --mirror


### Instaliavimo instrukcija
- Parsiųskite setup.exe ir paleiskite failą.
- Leiskite parsiųsti į C:/Program files/VU/Vardenis-Pavardenis.
- Pažymėkite sukurti shortcut darbalaukyje.
- Spauskite Finish.

## v3.0
### Vector funkcijos
#### pop_back
Removes the last element of the container. 
```cpp
Vector<int> myVector;
        int sum = 0;
        myVector.push_back(100);
        myVector.push_back(200);
        myVector.push_back(300);

        while (!myVector.empty()) {
            sum += myVector.back();
            myVector.pop_back();
        }
```
Rezultatas
```cpp
myVector elementai susideda į sumą: 600
```

#### push_back
Appends the given element value to the end of the container.
```cpp
Vector<int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);

        cout << "myVector susideda iš:";
        for (Vector<int>::size_type i = 0; i < myVector.size(); i++)
            cout << ' ' << myVector[i];
        cout << '\n';
```
Rezultatas
```cpp
myVector susideda iš: 1 2 3
```

#### shrink_to_fit
Reduces memory usage by freeing unused memory.
```cpp
 Vector<int> myVector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        myVector.reserve(20);
        cout << "Talpa prieš shrink_to_fit: " << myVector.capacity() << endl;
        myVector.shrink_to_fit();
        cout << "Talpa po shrink_to_fit: " << myVector.capacity() << endl;
```
Rezultatas
```cpp
Talpa prieš shrink_to_fit: 20
Talpa po shrink_to_fit: 10
```

#### begin
Returns an iterator to the first element of the vector.
```cpp
 Vector<int> myVector;
        for (int i = 1; i <= 5; i++) myVector.push_back(i);

        cout << "myVector susideda iš:";
        for (Vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
        cout << ' ' << *it;
        cout << '\n';
```
Rezultatas
```cpp
myVector susideda iš: 1 2 3 4 5
```

#### resize
Changes the number of elements stored.
```cpp
Vector<int> myVector;
        for (int i = 1; i < 10; i++) myVector.push_back(i);

        myVector.resize(5);
        myVector.resize(8, 100);
        myVector.resize(12);

        cout << "myVector susideda iš:";
        for (Vector<int>::size_type i = 0; i < myVector.size(); i++)
            cout << ' ' << myVector[i];
        cout << '\n';
```
Rezultatas
```cpp
myVector susideda iš: 1 2 3 4 5 100 100 100 0 0 0 0
```

### std::vector vs Vector
Kodas yra [vectorVsVector().](https://github.com/zubarev4/Pazymio-skaiciuokle3/blob/v3.0/vectors/vektoriai.cpp#L335C1-L365)

Kiek vidutiniškai laiko užtrunka  std::vector tipo ir Jūsų Vector tipo tuščius vektorius užpildyti: 10000, 100000, 1000000, 10000000 ir 100000000 int elementų naudojant push_back() funkciją:
|               |    10 000     |    100 000    |   1 000 000   |  10 000 000   |  100 000 000  |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
|  std::vector  |   0.000559s   |   0.000984s   |   0.014556s   |   0.133064s   |   1.167885s   |
|    Vector     |   0.000999s   |   0.001039s   |   0.015117s   |   0.165021s   |   1.522337s   |

Atminties perskirstymai užpildant 100 000 000 elementų: 
```cpp
Atmintis buvo perskirstyta 27 kartų su std::vector
Atmintis buvo perskirstyta 27 kartų su Vector
```
#### Duomenų apdorojimas
Vector
|               |    100 000     |    1 000 000    |   10 000 000   | 
| ------------- | ------------- | ------------- | ------------- |
|  Skaitymas iš failo =  |   0.000559s   |   0.000984s   |   0.014556s   |  
|    Studentų rūšiavimas =    |   0.000999s   |   0.001039s   |   0.015117s   |   
|    Studentų skirstymas =    |   0.000999s   |   0.001039s   |   0.015117s   |   
|    Studentų išvedimas =    |   0.000999s   |   0.001039s   |   0.015117s   |   
|    Visos programos veikimo laikas =    |   0.000999s   |   0.001039s   |   0.015117s   |   

std::vector
|               |    100 000     |    1 000 000    |   10 000 000   | 
| ------------- | ------------- | ------------- | ------------- |
|  Skaitymas iš failo =  |   0.000559s   |   0.000984s   |   0.014556s   |  
|    Studentų rūšiavimas =    |   0.000999s   |   0.001039s   |   0.015117s   |   
|    Studentų skirstymas =    |   0.000999s   |   0.001039s   |   0.015117s   |   
|    Studentų išvedimas =    |   0.000999s   |   0.001039s   |   0.015117s   |   
|    Visos programos veikimo laikas =    |   0.000999s   |   0.001039s   |   0.015117s   |   
