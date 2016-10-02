#include <iostream>
#include "utils.h"

using namespace std;

string KEY = "noatrbecfuxdqgylkhvijmpzws";

string encrypt(string plaintext) {
    string ciphertext = plaintext;
    bool lower = false;

    for (int i = 0; i < plaintext.length(); i++) {

        char ch = (char)plaintext[i];

        if (is_lower(ch)) {
            lower = true;
        } else {
            lower = false;
        }

        int k = char_to_int(ch);

        if (k >= 0 && k <=25) {
            if (lower) {
                ciphertext[i] = KEY[k];
            } else {
                ciphertext[i] = toupper(KEY[k]);
            }
        }

    }

    return ciphertext;
}

string decrypt(string ciphertext) {
    string plaintext = ciphertext;
    bool lower = false;

    for (int i = 0; i < ciphertext.length(); i++) {

        char ch = (char)ciphertext[i];

        if (is_lower(ch)) {
            lower = true;
        } else {
            lower = false;
        }

        int pos = KEY.find(tolower(ch));

        if (pos >= 0 && pos<= 25) {
            plaintext[i] = int_to_char(pos, lower);
        }

    }

    return plaintext;
}
int main()
{
    cout<<decrypt(encrypt("Created by Arfat Salman."));
    return 0;
}
