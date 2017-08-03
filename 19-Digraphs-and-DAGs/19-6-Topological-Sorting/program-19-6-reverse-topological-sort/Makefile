# compiler
CC = g++
# flags
CFLAGS = -Wall
# general dependencies
DEPS = ../../../17-Graph-Properties-and-Types/17-4-Adj-Lists-Representation/IO.cc ../../../17-Graph-Properties-and-Types/17-4-Adj-Lists-Representation/sparseMultiGRAPH.cpp dagTS.cc
# object files
OBJ = IO.o sparseMultiGRAPH.o dagTS.o
# main file name
TARGET = main.cc
# out file name
OUT = program-19-6.x
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
