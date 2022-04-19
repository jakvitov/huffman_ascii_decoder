/**
 * This header file contains structures and functions that are used
 * to build a huffman code tree
 * Closer description of the used compression method is in the readme file
 */

#ifndef HUFFMAN_HUFFMANCONSTRUCTOR_H
#define HUFFMAN_HUFFMANCONSTRUCTOR_H

//Tree node structure
struct treeNode{
    treeNode * right = nullptr;
    treeNode * left = nullptr;
    char value = -100;
};

//Construct Huffman tree from the beginning of the file
void hufConstr(bitReader & reader, treeNode ** root){
    char bit = reader.nextBit();
    if (bit == '0'){
        auto * node = new treeNode;
        node->value = -100;
        (*root) = node;
        hufConstr(reader,&(*root)->left);
        hufConstr(reader,&(*root)->right);
        return;
    }
    else if (bit == '1'){
        auto * node = new treeNode;
        string character = reader.nextByte();
        char val = toChar(character);
        node->value = val;
        (*root) = node;
        return;
    }
        //We read 8 => fail flag
    else {
        throw std::invalid_argument("End of file!");
    }
}

//A function to delete the tree and free all the taken memory
void hufDelete(treeNode ** root){
    if((*root)->right){
        hufDelete(&(*root)->right);
    }
    if((*root)->left){
        hufDelete(&(*root)->left);
    }
    if(!(*root)->right && !(*root)->left){
        delete(*root);
        (*root) = nullptr;
        return;
    }
}

//A debugging function used to print the huffman tree
void printTree(treeNode * root){
    cout << root->left->value << endl;
    cout << root->right->right->right->value << endl;
    cout << root->right->right->left->value << endl;
    cout << root->right->left->left->value << endl;
    cout << root->right->left->right->value << endl;
}

//Build and return the next character using the recursive traversal of the
//Huffman tree given by pointer to it's root node
char buildChar (bitReader & reader, treeNode ** root){
    treeNode * temp = *root;
    char scanned_bit;
    while (temp->value == -100){
        scanned_bit = reader.nextBit();
        if (scanned_bit == '0'){
            temp = temp->left;
        }
        else if (scanned_bit == '1') {
            temp = temp->right;
        }
            //We scanned 0
        else {
            throw std::invalid_argument("End of file");
        }
    }
    return temp->value;
}

//Read rest of the file and translate using the given huffman tree root node
string translChunk(bitReader & reader, treeNode ** root, bool & last_chunk){
    char curr_chunk;
    int scanned_count = 0;
    string result;
    //First read the chunk bite
    curr_chunk = reader.nextBit();
    //If the chunk is 4096 characters long
    if (curr_chunk == '1'){
        while (scanned_count != 4096){
            try {
                result.push_back(buildChar(reader, root));
                scanned_count ++;
            }
            catch (std::invalid_argument & e){
                throw std::invalid_argument("File not opened!");
            }
        }
    }
        //If the chunk is shorter and last
    else if (curr_chunk == '0'){
        //We scan the next 12 bites including the lenght of the chunk
        string str_lenght;
        for (int i = 0; i < 12; i++){
            str_lenght.push_back(reader.nextBit());
        }
        int int_lenght = binToDec(str_lenght);
        while (scanned_count != int_lenght){
            result.push_back(buildChar(reader, root));
            scanned_count ++;
        }
        last_chunk = true;
    }
    return result;
}

#endif //HUFFMAN_HUFFMANCONSTRUCTOR_H
