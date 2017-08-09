# compiler
CC = g++
# flags
CFLAGS = -Wall
# general dependencies
DEPS = ../../17-Graph-Properties-and-Types/17-4-Adj-Lists-Representation/IO.cc ../../17-Graph-Properties-and-Types/17-4-Adj-Lists-Representation/sparseMultiGRAPH.cpp BubbleSC.cc ../19-6-Topological-Sorting/program-19-8-source-queue-topological-sort/dagTS.cc
# object files
OBJ = IO.o sparseMultiGRAPH.o BubbleSC.o dagTS.o
# main file name
TARGET = main.cc
# out file name
OUT = bubble.x
# standard
STD = -std=c++11


all : $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(STD) $(CFLAGS) $(TARGET) -o $(OUT) $(OBJ)

$(OBJ): $(DEPS)
	$(CC) $(STD) -c $(DEPS)

.PHONY : clean
clean:
	rm -rf $(wildcard *.o) $(wildcard *~)
