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
