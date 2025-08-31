all: Hello_World Mattrix_Mult File_IO User_Input

Hello_World: Hello_World.cpp
	g++ -o Hello_World Hello_World.cpp -std=c++11 -O2

Mattrix_Mult: Matrix_Mult.cpp
	g++ -o Matrix_Mult Matrix_Mult.cpp -std=c++11 -O2

File_IO: File_IO.cpp
	g++ -o File_IO File_IO.cpp -std=c++11 -O2

User_Input: User_Input.cpp
	g++ -o User_Input User_Input.cpp -std=c++11 -O2

clean:
	rm -f Hello_World Matrix_Mult File_IO io_test_c_plus_plus.txt io_test_python.txt User_Input