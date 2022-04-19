/**
 * bitReader is a class that provides a buffered reader from a file
 * It returns data as a single char bit '0'/'1' or a string of 8 bits
 */

#ifndef HW01_BITREADER_H
#define HW01_BITREADER_H

using namespace std;

#include <fstream>
#include <string>

class bitReader {
private:

    ifstream file;
    string buffer;
    const int buffer_size = 4;

    void fill_buffer();

public:

    bitReader(const std::string &fileName);

    ~bitReader();

    //Return next bit from the file as a char ('0'/'1')
    char nextBit();

    //Return next byte of the data as a string - "01010010"
    string nextByte();
};


#endif //HW01_BITREADER_H