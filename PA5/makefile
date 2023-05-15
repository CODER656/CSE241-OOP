all: compile run clean

compile:
	@g++ -std=c++11 main.cpp bulldozer.cpp optimusprime.cpp roomba.cpp humanic.cpp robot.cpp robocop.cpp world.cpp -o test
	@./test

run:
	@./test

clean:
	@rm -f *.o
	@rm -f test


debug:
	@g++ -g -o test  main.cpp bulldozer.cpp optimusprime.cpp roomba.cpp humanic.cpp robot.cpp robocop.cpp world.cpp  -std=c++11
	@./test