#This is a makefile bash script for the Huffman decoder
#Launch this file with bash to build the executable file

#!bin/bash

g++ -c main.cpp
g++ -c bitReader.cpp
g++ -c bitReader.h
g++ -c supplyFunctions.h
g++ -c huffmanConstructor.h
g++ -c decodeFunctions.h
g++ -o main main.o bitReader.o decodeFunctions.h