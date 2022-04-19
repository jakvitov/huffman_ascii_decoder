/**
 * This header file contains supply functions for the other classes
 *
 */
#ifndef HUFFMAN_SUPPLYFUNCTIONS_H
#define HUFFMAN_SUPPLYFUNCTIONS_H

#include "bitReader.h"
#include "supplyFunctions.h"
#include "huffmanConstructor.h"

//Basic power function
int pow(int base, int exponent){
    int origbase = base;
    if (exponent == 0){
        return 1;
    }
    for (int i = 1; i < exponent; i++){
        base *= origbase;
    }
    return base;
}

//Transform a binary string into a char
char toChar(string bin){
    char result = 0;
    int exponent = 0;
    for (int i = (bin.length() - 1); i >= 0; i--){
        result += ((bin.at(i) - '0') * pow(2,exponent ++));
    }
    return result;
}

//Translate binary string into a number
int binToDec(string bin){
    int result = 0;
    int exponent = 0;
    for (int i = (bin.length() - 1); i >= 0; i--){
        result += ((bin.at(i) - '0') * pow(2,exponent ++));
    }
    return result;
}


#endif //HUFFMAN_SUPPLYFUNCTIONS_H
