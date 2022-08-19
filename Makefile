
all: main

run: main
	./main

main: main.o FileReader.o Student.o DomesticStudent.o InternationalStudent.o stu_sort.o ToeflScore.o error.o merge.o UserIO.o UnitTest.o filter.o
	g++ -g -o main main.o FileReader.o Student.o DomesticStudent.o InternationalStudent.o stu_sort.o ToeflScore.o error.o merge.o UserIO.o UnitTest.o filter.o

main.o: main.cpp
	g++ -std=c++11 -g -c main.cpp

FileReader.o: FileReader.cpp
	g++ -std=c++11 -g -c FileReader.cpp

Student.o: Student.cpp
	g++ -std=c++11 -g -c Student.cpp

DomesticStudent.o: DomesticStudent.cpp
	g++ -std=c++11 -g -c DomesticStudent.cpp

InternationalStudent.o: InternationalStudent.cpp
	g++ -std=c++11 -g -c InternationalStudent.cpp

stu_sort.o: stu_sort.cpp
	g++ -std=c++11 -g -c stu_sort.cpp

ToeflScore.o: ToeflScore.cpp
	g++ -std=c++11 -g -c ToeflScore.cpp
	
error.o: error.cpp
	g++ -std=c++11 -g -c error.cpp

merge.o: merge.cpp
	g++ -std=c++11 -g -c merge.cpp

UserIO.o: UserIO.cpp
	g++ -std=c++11 -g -c UserIO.cpp

UnitTest.o: UnitTest.cpp
	g++ -std=c++11 -g -c UnitTest.cpp

filter.o: filter.cpp
	g++ -std=c++11 -g -c filter.cpp

clean:
	rm -rf main main.o FileReader.o Student.o DomesticStudent.o InternationalStudent.o stu_sort.o ToeflScore.o merge.o error.o UserIO.o UnitTest.o filter.o *~

delete:
	rm -rf main.cpp FileReader.cpp Student.cpp DomesticStudent.cpp InternationalStudent.cpp stu_sort.cpp ToeflScore.cpp error.cpp merge.cpp UserIO.cpp FileReader.hpp Student.hpp DomesticStudent.hpp InternationalStudent.hpp stu_sort.hpp ToeflScore.hpp error.hpp merge.hpp UserIO.hpp domestic-stu.txt international-stu.txt UnitTest.cpp UnitTest.cpp filter.cpp filter.hpp
