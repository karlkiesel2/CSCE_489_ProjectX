all: Hello_World Mattrix_Mult

Hello_World: Hello_World.cpp
	g++ -o Hello_World Hello_World.cpp -std=c++11 -O2

Mattrix_Mult: Matrix_Mult.cpp
	g++ -o Matrix_Mult Matrix_Mult.cpp -std=c++11 -O2

clean:
	rm -f Hello_World Matrix_Mult