/**
 * The main function where the simple client interface takes place
 */

#include <iostream>
#include <iomanip>
#include "bitReader.h"
#include "supplyFunctions.h"
#include "huffmanConstructor.h"
#include "decodeFunctions.h"

using namespace std;

int main() {
    string inputFile;
    string outputFile;

    cout << "Wellcome to the Huffman ASCII decoder!" << endl;
    cout << setfill('-') << setw(40) << "" << endl;

    cout << "Insert the name of the file that you'd like to decode:" << endl;
    cin >> inputFile;
    cout << "Insert the name of the result file:" << endl;
    cin >> outputFile;

    cout << "Translating..." << endl;

    if (decodeFile(inputFile.c_str(), outputFile.c_str())){
        cout << setfill('*') << setw(14) << "" << endl;
        cout << "Completed!" << endl;
        cout << setfill('*') << setw(14) << "" << endl;
    }
    else {
        cout << setfill('*') << setw(14) << "" << endl;
        cout << "An error occured while translating the file" << endl;
        cout << "The compressed file is corrupted or the file path given was invalid." << endl;
        cout << setfill('*') << setw(14) << "" << endl;
    }

    return 0;
}
