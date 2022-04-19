/**
 * A header file with the file decoding functions
 */

#ifndef HUFFMAN_DECODEFUNCTIONS_H
#define HUFFMAN_DECODEFUNCTIONS_H

#include <fstream>
#include "bitReader.h"
#include "supplyFunctions.h"
#include "huffmanConstructor.h"

bool decodeFile ( const char * inputFile, const char * outputFile )
{
    treeNode * root = nullptr;
    ofstream out;
    try {
        bitReader reader(inputFile);
        out.open(outputFile);
        if (out.fail() || out.bad()){
            cout << "Output file cannot be opened!" << endl;
            throw std::invalid_argument("File not opened!");
        }
        hufConstr(reader, &root);
        bool last_chunk = false;
        while (!last_chunk){
            if (out.fail() || out.bad()){
                throw std::invalid_argument("File not opened!");
            }
            string chunk = translChunk(reader, &root, last_chunk);
            out << chunk;
        }
    }
    catch (std::invalid_argument & e){
        out.close();
        hufDelete(&root);
        return false;
    }
    out.close();
    hufDelete(&root);
    return true;
}

#endif //HUFFMAN_DECODEFUNCTIONS_H
