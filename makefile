.PHONY: all clean run
all: ./bin/main.o ./bin/unit.o 
	g++ ./bin/main.o ./bin/unit.o -o ./bin/test 
./bin/main.o: ./main.cpp ./include/*.h
	g++ -DDEBUG -c main.cpp -I ./include -o ./bin/main.o 

./bin/unit.o: ./src/unit.cc ./include/*.h
	g++ -DDEBUG -c ./src/unit.cc -I ./include -o ./bin/unit.o 

 

run:
	./bin/test
clean:
	rm -rf ./bin/test ./bin/main.o ./bin/unit.o 
