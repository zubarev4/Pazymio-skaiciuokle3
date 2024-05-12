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
| Skaitymas iš failo =  | 4.72s                         | 5.43143s                       |
| Studentų rūšiavimas = | 0.3307s                       | 1.80046s                       | 
| Studentų skirstymas = | 0.8901s                       | 2.01125s                       | 
| Visos programos veikimo laikas = | 5.9471s                       | 9.243s                       | 

                                                 10000000 Studentų

|                       | Struct                        | Class                         |
|-----------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 10.0641s                       | 46.0491s                      | 
| Studentų rūšiavimas = | 1.10318s                       | 21.2713s                      |
| Studentų skirstymas = | 1.91224s                       | 22.9681s                       |
| Visos programos veikimo laikas = | 13.07952s                       | 90.33s                       | 

### Flagai

Tyrimai atlikti su 10000000 failu.

                               Class
|                       | -O1                        | -O2                          | -O3                         |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 45.2827s                         | 46.0491s                       | 45.1367s                       |
| Studentų rūšiavimas = | 22.1974s                       | 21.2713s                       | 21.3836s                       |
| Studentų skirstymas = | 23.9054s                       | 22.9681s                       | 23.1262s                       |
| Visos programos veikimo laikas = | 91s                       | 90.33s                       | 92s                       |
| .exe dydis = | 117 KB                       | 118 KB                       | 129 KB       |

                               Struct
|                       | -O1                        | -O2                          | -O3                         |
|-----------------------|-------------------------------|-------------------------------|-------------------------------|
| Skaitymas iš failo =  | 11.6503s                         | 10.0641s                       | 10.0112s                       |
| Studentų rūšiavimas = | 2.9477s                       | 1.10318s                       | 3.13828s                       |
| Studentų skirstymas = | 6.46039s                       | 1.91224s                       | 6.93389s                       |
| Visos programos veikimo laikas = | 19.56s                       | 13.07952s                       | 19.025s                       |
| .exe dydis = | 112 KB                       | 120 KB                       | 129 KB       |
