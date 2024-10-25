SRC = algorithms
CC = gcc
CXX = g++
CXXFLAGS = -O2 -Wall -Wextra -Wshadow -std=c++20 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fstack-protector
CXXFLAGS += -I$(SRC)

files := $(wildcard *.cpp)

all: main.o AdvancedSort.o BasicSort.o AlgorithmTesting.o NoComparisonSort.o FlashSort.o DataGenerator.o CommandProcess.o GenerateInputData.o
	$(CXX) $(CXXFLAGS) $^ -o main.exe

AdvancedSort.o: $(SRC)/AdvancedSort.h $(SRC)/AdvancedSort.cpp $(SRC)/Utilities.h $(SRC)/BasicSort.h
	$(CXX) $(CXXFLAGS) -g -c $(SRC)/AdvancedSort.cpp

BasicSort.o: $(SRC)/BasicSort.cpp $(SRC)/BasicSort.h $(SRC)/Utilities.h
	$(CXX) $(CXXFLAGS) -g -c $(SRC)/BasicSort.cpp

AlgorithmTesting.o: AlgorithmTesting.cpp AlgorithmTesting.h $(SRC)/BasicSort.h $(SRC)/AdvancedSort.h $(SRC)/NoComparisonSort.h $(SRC)/FlashSort.h
	$(CXX) $(CXXFLAGS) -g -c AlgorithmTesting.cpp	

NoComparisonSort.o: $(SRC)/NoComparisonSort.cpp $(SRC)/NoComparisonSort.h
	$(CXX) $(CXXFLAGS) -g -c $(SRC)/NoComparisonSort.cpp

FlashSort.o: $(SRC)/FlashSort.cpp $(SRC)/FlashSort.h $(SRC)/Utilities.h $(SRC)/BasicSort.h
	$(CXX) $(CXXFLAGS) -g -c $(SRC)/FlashSort.cpp

DataGenerator.o: DataGenerator.cpp DataGenerator.h
	$(CXX) $(CXXFLAGS) -g -c DataGenerator.cpp

CommandProcess.o: CommandProcess.cpp CommandProcess.h $(SRC)/BasicSort.h $(SRC)/AdvancedSort.h $(SRC)/NoComparisonSort.h $(SRC)/FlashSort.h DataGenerator.h
	$(CXX) $(CXXFLAGS) -g -c CommandProcess.cpp

GenerateInputData.o: GenerateInputData.cpp GenerateInputData.h DataGenerator.h
	$(CXX) $(CXXFLAGS) -g -c GenerateInputData.cpp

main.o: main.cpp $(SRC)/BasicSort.h $(SRC)/AdvancedSort.h AlgorithmTesting.h $(SRC)/NoComparisonSort.h $(SRC)/FlashSort.h DataGenerator.h GenerateInputData.h
	$(CXX) $(CXXFLAGS) -g -c main.cpp

run: main.exe
	main.exe < input.txt > output.txt

clean:
	rm -f *.o *.exe