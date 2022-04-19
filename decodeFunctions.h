/**
 * A header file with the file decoding functions
 */

#ifndef HUFFMAN_DECODEFUNCTIONS_H
#define HUFFMAN_DECODEFUNCTIONS_H

#include "bitReader.h"
#include "supplyFunctions.h"
#include "huffmanConstructor.h"

bool decodeFile ( const char * inputFile, const char * outputFile )
{
    try {
        bitReader reader(inputFile, std::ifstream());
        ofstream out(outputFile);
        if (out.fail()){
            throw std::invalid_argument("File not opened!");
        }
        treeNode * root;
        hufConstr(reader, &root);
        bool last_chunk = false;
        while (!last_chunk){
            string chunk = translChunk(reader, &root, last_chunk);
            out << chunk;
        }
        hufDelete(&root);
    }
    catch (std::invalid_argument & e){
        return false;
    }
    return true;
}

#endif //HUFFMAN_DECODEFUNCTIONS_H
