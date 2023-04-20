all: clean compile run

compile: main.cpp util.cpp util.h
	@g++ -o test main.cpp util.cpp -std=c++11

run:
	./test 

clean:
	@rm -f *.o
	@rm -f test

debug:
	@g++ -g -o test  main.cpp util.cpp util.h -std=c++11
	@./test
