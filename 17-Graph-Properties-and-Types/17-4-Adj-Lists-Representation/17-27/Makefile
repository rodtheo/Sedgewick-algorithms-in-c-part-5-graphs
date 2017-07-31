# compiler
CC = g++
# flags
CFLAGS = -Wall
# general dependencies
DEPS = ../IO.cc ../sparseMultiGRAPH.cpp
# object files
OBJ = IO.o sparseMultiGRAPH.o
# main file name
TARGET = 17-27.cc
# out file name
OUT = 17-27.x
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
