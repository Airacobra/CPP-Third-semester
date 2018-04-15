#Makefile 
#PPO
#ⓒ Kamil Kucharski
#WFiIS 

__Start__: Array
	./Array

Array: Main.o MyArray.o
	g++ Main.o MyArray.o -o Array

Main.o: Main.cpp Main.h
	g++ -Wall -Wextra -pedantic -g -c Main.cpp

MyArray.o: MyArray.cpp MyArray.h
	g++ -Wall -Wextra -pedantic -g -c MyArray.cpp

clean:
	rm *.o
	rm Array

run:
	./Array