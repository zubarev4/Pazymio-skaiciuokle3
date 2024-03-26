vektoriai:
	g++ -c vektoriai.cpp

failu-generavimas:
	g++ -c failu-generavimas.cpp

main-vektoriai: vektoriai failu-generavimas
	g++ -o main-vektoriai main-vektoriai.cpp vektoriai.o failu-generavimas.o
