all: compile run clean

compile:
	@g++ main.cpp Student.cpp  Course.cpp  SchoolManagerSystem.cpp  -o test
	@./test

run:
	@./test

clean:
	@rm -f *.o
	@rm -f test


debug:
	@g++ -g -o test  main.cpp Student.cpp Student.h Course.cpp Course.h SchoolManagerSystem.cpp SchoolManagerSystem.h -std=c++11
	@./test