# compiler
CC = g++
# flags
CFLAGS = -Wall
# general dependencies
DEPS = ../IO.cc ../sparseMultiGRAPH.cpp ../DFS.cpp
# object files
OBJ = IO.o sparseMultiGRAPH.o DFS.o
# main file name
TARGET = main.cc
# out file name
OUT = ex-DFS.x
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
