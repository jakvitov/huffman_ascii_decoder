#include <iostream>
#include "bitReader.h"

void bitReader::fill_buffer(){
    char * temp_buffer = new char [buffer_size];
    this->file.read(temp_buffer, buffer_size);
    if (file.bad() && !file.eof()){
        throw std::invalid_argument("IOstream error!");
    }
    //We loop trough the temporary buffer field and parse all chars into binary and
    //add it into buffer
    for (int i = 0; i < file.gcount(); i ++){
        char byte = temp_buffer[i];
        for (int k = 0; k < 8; k++) {
            if ((byte & 128) == 128) {
                byte <<= 1;
                this->buffer.append("1");
            }  else {
                byte <<= 1;
                this->buffer.append("0");
            }
        }
    }
    delete[] (temp_buffer);
}

bitReader::bitReader(const std::string &fileName){
    file.open(fileName, ios::binary);
    if (file.fail()){
        cout << "The file: " << fileName << " cannot be opened!" << endl;
        throw std::invalid_argument("File not opened!");
    }
}

bitReader::~bitReader() {
    file.close();
}

//Return next bit, if file has ended and buffer is empty return 8
//8 is reserved value for error-flag
char bitReader::nextBit(){
    //We fill the buffer, if it's empty or too small
    if (this->buffer.empty() || this->buffer.length() < 5){
        this->fill_buffer();
    }
    if (this->buffer.empty()){
        return '8';
    }
    char result = buffer.at(0);
    buffer.erase(0,1);
    return result;
}

//Return a string containing next byte of the file, if file has ended
//and buffer is empty, return empty string
string bitReader::nextByte(){
    if (buffer.empty() || buffer.length() < 9){
        this->fill_buffer();
    }
    if (this->buffer.empty()){
        return "";
    }
    string result;
    if (buffer.size() >= 8){
        result = buffer.substr(0,8);
        buffer.erase(0,8);
    }
    else {
        result = buffer.substr(0, buffer.size());
        buffer.erase(0, buffer.size());
    }
    return result;
}
