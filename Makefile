all: dz1

dz1: main.o dop.o fun.o huge.o mul.o var.o
	g++ main.o dop.o fun.o huge.o mul.o var.o -o dz1 -lfltk
	
main.o: main.cpp
	 g++ -c main.cpp
    
dop.o: dop.cpp
	 g++ -c dop.cpp
    
fun.o: fun.cpp
	 g++ -c fun.cpp

huge.o: huge.cpp
	 g++ -c huge.cpp
    
mul.o: mul.cpp
	 g++ -c mul.cpp

var.o: var.cpp
	 g++ -c var.cpp
	 
clean:
	 rm -rf *.o dz1
