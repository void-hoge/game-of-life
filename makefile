CC = g++-9
PROGRAM = lifegame
STD = -std=c++17
OPTIM = -O3 -mtune=native -march=native -flto
FLAGS = -I/usr/local/Cellar/boost/1.70.0/include -I/usr/local/Cellar/boost/1.70.0/lib -pthread

$(PROGRAM).out: main.o board.o
	$(CC) $(STD) $(OPTIM) $(FLAGS) main.o board.o -o $(PROGRAM).out

main.o: main.cpp
	$(CC) $(STD) $(OPTIM) $(FLAGS) -c main.cpp -o main.o

board.o: board.cpp
	$(CC) $(STD) $(OPTIM) $(FLAGS) -c board.cpp -o board.o

clean:
	rm *.out
	rm *.o

run:
	./$(PROGRAM).out galaxy
