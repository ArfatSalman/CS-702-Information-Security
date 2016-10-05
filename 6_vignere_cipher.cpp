#include <iostream>
#include "utils.h"

using namespace std;

string encrypt(string plaintext, string key) {

    string ciphertext = plaintext;
    int key_offset = 0;

    for (int i = 0; i < plaintext.length(); i++) {

        int p = char_to_int(plaintext[i]);

        int k = char_to_int((char)key[key_offset]);

        if (p >= 0 && p < 26) {

            char c = int_to_char((p+k) % 26, islower(plaintext[i]));

            ciphertext[i] = c;

            key_offset = (key_offset + 1) % key.length();
        }
    }

    return ciphertext;

}

string decrypt(string ciphertext, string key) {
    string plaintext = ciphertext;
    int key_offset = 0;

    for (int i = 0; i < ciphertext.length(); i++) {

        int c = char_to_int(ciphertext[i]);

        int k = char_to_int((char)key[key_offset]);

        if (c >= 0 && c < 26) {

            char p = int_to_char(mod(c-k, 26), islower(ciphertext[i]));

            plaintext[i] = p;

            key_offset = (key_offset + 1) % key.length();
        }
    }

    return plaintext;
}

int main()
{
    // Key should be smaller than 26 letters
    cout<<decrypt(encrypt("Implemented by Arfat Salman.", "arfat"), "arfat");
    return 0;
}
