#include <iostream>
#include "utils.h"

using namespace std;

string format(string plaintext, int col) {


    if (plaintext.length() % col == 0) {
        return plaintext;
    }

    int bog_chr = col - (plaintext.length() % col);

    for (int i = 0; i < bog_chr; i++) {
        plaintext += "X";
    }
    return plaintext;
}

string encrypt(string plaintext, int col) {

    plaintext = format(plaintext, col);

    string ciphertext = plaintext;
    int pos = 0;

    for (int i = 0; i < col; i++) {
        int j = i;

        while (j < plaintext.length()) {
            ciphertext[pos++] = plaintext[j];

            j += col;
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, int col) {
    string plaintext = ciphertext;

    int pos = 0;
    int new_col = ciphertext.length()/col;

    for (int i = 0; i < new_col; i++) {

        int j = i;

        while (j < ciphertext.length()) {
            plaintext[pos++] = ciphertext[j];

            j += new_col;
        }
    }
    return plaintext;
}

int main()
{
    // Key should be smaller than 26 letters
    cout<<encrypt("meetmeatthepark", 4);
    cout<<endl<<decrypt("mmtaeehreaekttpX", 4);

    return 0;
}
