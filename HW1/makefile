all: clean compile run

compile: main.cpp utils.cpp utils.h
	@g++ -o test main.cpp utils.cpp -std=c++11

run:
	./test

clean:
	@rm -f *.o
	@rm -f test

