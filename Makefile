all: Hello_World_O0 Hello_World_O2 Matrix_Mult_O0 Matrix_Mult_O2 File_IO_O0 File_IO_O2 User_Input_O0 User_Input_O2 Parallel_O0 Parallel_O2 Parallel_IO_O0 Parallel_IO_O2

Hello_World_O0: Hello_World.cpp
	g++ -o Hello_World_O0 Hello_World.cpp -std=c++11 -O0

Hello_World_O2: Hello_World.cpp
	g++ -o Hello_World_O2 Hello_World.cpp -std=c++11 -O2

Matrix_Mult_O0: Matrix_Mult.cpp
	g++ -o Matrix_Mult_O0 Matrix_Mult.cpp -std=c++11 -O0

Matrix_Mult_O2: Matrix_Mult.cpp
	g++ -o Matrix_Mult_O2 Matrix_Mult.cpp -std=c++11 -O2

File_IO_O0: File_IO.cpp
	g++ -o File_IO_O0 File_IO.cpp -std=c++11 -O0

File_IO_O2: File_IO.cpp
	g++ -o File_IO_O2 File_IO.cpp -std=c++11 -O2

User_Input_O0: User_Input.cpp
	g++ -o User_Input_O0 User_Input.cpp -std=c++11 -O0

User_Input_O2: User_Input.cpp
	g++ -o User_Input_O2 User_Input.cpp -std=c++11 -O2

Parallel_O0: Parallel.cpp
	g++ -o Parallel_O0 Parallel.cpp -std=c++11 -O0 -pthread

Parallel_O2: Parallel.cpp
	g++ -o Parallel_O2 Parallel.cpp -std=c++11 -O2 -pthread

Parallel_IO_O0: Parallel_IO.cpp
	g++ -o Parallel_IO_O0 Parallel_IO.cpp -std=c++11 -O0 -pthread

Parallel_IO_O2: Parallel_IO.cpp
	g++ -o Parallel_IO_O2 Parallel_IO.cpp -std=c++11 -O2 -pthread

clean:
	rm -f Hello_World_O0 Hello_World_O2 Matrix_Mult_O0 Matrix_Mult_O2 File_IO_O0 File_IO_O2 io_test_c_plus_plus.txt io_test_python.txt User_Input_O0 User_Input_O2 Parallel_O0 Parallel_O2 Parallel_IO_O0 Parallel_IO_O2 io_test_c_plus_plus_parallel_write.txt io_test_python_parallel_write.txt