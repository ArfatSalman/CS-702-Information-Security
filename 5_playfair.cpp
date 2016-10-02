#include <iostream>
#include "utils.h"

using namespace std;

int ROW_COL[2];
string FILLER = "X";
string KEY[] =  {
                    "LGDBA",
                    "QMHEC",
                    "URNIF",
                    "XVSOK",
                    "ZYWTP"
                };

int* row_col(char ch) {
    ch = toupper(ch);
    for (int i = 0; i < 5; i++) {

        ROW_COL[0] = i;

        ROW_COL[1] = KEY[i].find(ch);

        if (ROW_COL[1] != -1) {
            break;
        }
    }

    if (ROW_COL[1] == -1) {
        ROW_COL[0] = -1;
    }

    return ROW_COL;
}

string preformat(string plaintext) {

    string formattedtext = plaintext;
    int offset = 0;


    for (int i = 0; i < formattedtext.length(); i++) { // Removing J
        if (formattedtext[i] == 'j') {
            formattedtext[i] = 'i';
        }
    }

    for (int i = 1; i < plaintext.length(); i++) {

        if (plaintext[i] == plaintext[i-1]) {
            formattedtext.insert(i+offset,FILLER);
            offset++;
        }
    }

    if (formattedtext.length() % 2 != 0) {
        formattedtext += FILLER;
    }

    return formattedtext;
}

string pairwise_encrypt(string block) {

    char first = (char)block[0];
    char second = (char)block[1];
    string newBlock = block;

    int pos_1[2], pos_2[2];

    row_col(first);
    pos_1[0] = ROW_COL[0]; pos_1[1] = ROW_COL[1];

    row_col(second);
    pos_2[0] = ROW_COL[0]; pos_2[1] = ROW_COL[1];

    if ( pos_1[0] == pos_2[0] ) { // When rows are same

        newBlock[0] = KEY[ pos_1[0] ] [ (pos_1[1] + 1) % 5 ];
        newBlock[1] = KEY[ pos_2[0] ] [ (pos_2[1] + 1) % 5 ];

        return newBlock;
    }

    if ( pos_1[1] == pos_2[1]) { // when Columns are same

        newBlock[0] = KEY[ (pos_1[0] + 1 ) % 5 ] [ pos_1[1] ];
        newBlock[1] = KEY[ (pos_2[0] + 1 ) % 5 ] [ pos_2[1] ];

        return newBlock;
    }

    newBlock[0] = KEY[ pos_1[0] ] [ pos_2[1]  ];
    newBlock[1] = KEY[ pos_2[0] ] [ pos_1[1]  ];


    return newBlock;
}

int mod(int i, int j) {
    if (i % j < 0) {
        return (i%j) + j;
    }
    return i % j;
}

string pairwise_decrypt(string block) {

    char first = (char)block[0];
    char second = (char)block[1];
    string newBlock = block;

    int pos_1[2], pos_2[2];

    row_col(first);
    pos_1[0] = ROW_COL[0]; pos_1[1] = ROW_COL[1];

    row_col(second);
    pos_2[0] = ROW_COL[0]; pos_2[1] = ROW_COL[1];

    if ( pos_1[0] == pos_2[0] ) { // When rows are same

        newBlock[0] = KEY[ pos_1[0] ] [ mod(pos_1[1] - 1, 5) ];
        newBlock[1] = KEY[ pos_2[0] ] [ mod(pos_2[1] - 1, 5 )];

        return newBlock;
    }

    if ( pos_1[1] == pos_2[1]) { // when Columns are same

        newBlock[0] = KEY[ mod(pos_1[0] - 1, 5) ] [ pos_1[1] ];
        newBlock[1] = KEY[ mod(pos_2[0] - 1, 5) ] [ pos_2[1] ];

        return newBlock;
    }

    newBlock[0] = KEY[ pos_1[0] ] [  pos_2[1]  ];
    newBlock[1] = KEY[ pos_2[0] ] [  pos_1[1]  ];

    return newBlock;
}

string decrypt(string ciphertext) {

    string plaintext;

    for (int i = 0; i < ciphertext.length(); i = i + 2) {
        plaintext += pairwise_decrypt(ciphertext.substr(i, 2));
    }
    return plaintext;
}

string encrypt(string plaintext) {
    string formattedtext = preformat(plaintext);
    string ciphertext;

    for (int i = 0; i < formattedtext.length(); i = i + 2) {
        ciphertext += pairwise_encrypt(formattedtext.substr(i, 2));
    }
    return ciphertext;
}

int main()
{
    cout<<decrypt(encrypt("ArfatSalman")); // All J's will be changed to I's
    return 0;
}
