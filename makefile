all: battleship

battleship: battleship.o battleshipmain.o
	g++ battleship.o battleshipmain.o -o battleship

battleship.o: battleship.cpp
	g++ -c battleship.cpp

battleshipmain.o: battleshipmain.cpp
	g++ -c battleshipmain.cpp

clean:
	rm -rf *.o

