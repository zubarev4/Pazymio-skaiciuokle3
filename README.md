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

## v1.1
### Struct ir Class
                                            1000000 Studentų

|                       | Struct                        | Class                         |
|-----------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 3.72s                         | 4.1895s                       |
| Studentų rūšiavimas = | 0.3307s                       | 0.2467s                       | 
| Studentų skirstymas = | 0.8901s                       | 0.69167s                       | 
| Visos programos veikimo laikas = | 174s                       | 168s                       | 

                                                 10000000 Studentų

|                       | Struct                        | Class                         |
|-----------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 39.046s                       | 40.077s                      | 
| Studentų rūšiavimas = | 3.6826s                       | 2.9432s                      |
| Studentų skirstymas = | 9.9272s                       | 6.2989s                       |
| Visos programos veikimo laikas = | 174s                       | 168s                       | 

### Flagai

Tyrimai atlikti su 10000000 failu.

                               Class
|                       | -O1                        | -O2                          | -O3                         |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 43.8272s                         | 41.6687s                       | 41.7454s                       |
| Studentų rūšiavimas = | 3.41802s                       | 5.57437s                       | 2.92606s                       |
| Studentų skirstymas = | 7.04712s                       | 9.11836s                       | 6.30334s                       |
| Visos programos veikimo laikas = | 168s                       | 197s                       | 227s                       |
| .exe dydis = | 142 KB                       | 140 KB                       | 179 KB       |

                               Struct
|                       | -O1                        | -O2                          | -O3                         |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 26.6503s                         | 29.0225s                       | 28.0112s                       |
| Studentų rūšiavimas = | 2.9477s                       | 3.5303s                       | 3.13828s                       |
| Studentų skirstymas = | 6.46039s                       | 7.46403s                       | 6.93389s                       |
| Visos programos veikimo laikas = | 193s                       | 201s                       | 197s                       |
| .exe dydis = | 142 KB                       | 140 KB                       | 159 KB       |
