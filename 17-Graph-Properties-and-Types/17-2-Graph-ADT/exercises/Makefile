# compiler
CC = g++
# flags
CFLAGS = -Wall -g
# general dependencies
DEPS = ../IO.o ../denseGRAPH.o
# object files
OBJ = main.cc ../IO.o ../denseGRAPH.o
# main file name
TARGET = main.cc
# out file name
OUT = out
# standard
# STD = -std=c99


all : $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJ)

$(OBJ): $(DEPS)
	$(CC) -c $(DEPS)

.PHONY : clean
clean:
	rm -rf $(wildcard *.o) $(wildcard *~)
