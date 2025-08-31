all: Hello_World

Hello_World: Hello_World.cpp
	g++ -o Hello_World Hello_World.cpp -std=c++11 -O2
clean:
	rm -f Hello_World