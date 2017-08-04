# compiler
CC = g++
# flags
CFLAGS = -Wall
# general dependencies
DEPS = ../IO.cc ../sparseMultiGRAPH.cpp ../DFSStats.cpp
# object files
OBJ = IO.o sparseMultiGRAPH.o DFSStats.o
# main file name
TARGET = main.cc
# out file name
OUT = DFS-stats.x
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
