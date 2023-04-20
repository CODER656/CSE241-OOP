all: clear clean compile run

compile:  driver2.cpp util.cpp util.h
	@g++ -o test  driver2.cpp util.cpp -std=c++11

run:
	./test

clean:
	@rm -f *.o
	@rm -f test

clear:
	@clear