# Antra užduotis: 
- Pratęskite (tuo pačiu ir patobulinkite) 1-osios užduoties Jūsų turimą programos realizaciją (versiją v1.0) taip, kad vietoje Jūsų sukurtos Studentas (StudentoInfo) ar dar kitaip pavadintos Studentų structūros jos pagrindu sukurkite class'ę.


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


## v1.1
- Padarytas "repozitorijos klonavimas".
- Struct ir Klasės versija ištirta su optimizavimo "flagais"

## v1.2
- Realizuoti visus reikiami "Rule of five" ir įvesties/išvesties operatoriai.
- Realizuoti metodai pilnai patikrinti (Visi konstruktoriai, kopijavimo, perkėlimo (move) metodai, destruktorius ir įvesties/išvesties metodai)

## v1.5
- Sukurtos dvi: bazinė (abstrakti) klasė - Zmogus, skirta bendrai aprašyti žmogų ir tuomet iš jos išvestinę (derived) klasę - Student. 
- Realizuota abstrakti klasė Zmogus, jos objektų kūrimas negalimas.
- Studento klasė išvestinė (derived) iš Žmogaus ir palaiko 1.2 versijoje realizuotą penkių metodų taisyklę. Visi realizuoti metodai Studento klasėje pilnai patikrinti (Visi konstruktoriai, kopijavimo, perkėlimo (move) metodai, destruktorius ir įvesties/išvesties metodai.

## v2.0
- Realizuoti ir demonstruojami unit test testai su savo klasė.
- Pateikta klasė, aprašanti dokumentacija HTML/TEX formatais.
