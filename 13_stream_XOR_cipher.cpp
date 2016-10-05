#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "utils.h"

using namespace std;

string char_to_bin(char c) {

    string output = "00000000";

    int ch = c;
    int pos = 7;

    while ( ch > 0) {
        if (ch % 2 == 0) {
            output[pos--] = '0';
        } else {
            output[pos--] = '1';
        }

        ch = ch / 2;
    }

    return output;
}

string str_to_bin(string text) {
    string output = "";

    for (int i  = 0; i < text.length(); i++) {
        output += char_to_bin(text[i]);
    }

    return output;
}

string XOR(string p, string q) {

    if (p.length() != q.length()) {
        cout<<"The key and message should be of same length";
        return "";
    }

    string output = p;

    for (int i = 0; i < p.length(); i++) {
        if (p[i] == q[i]) {
            output[i] = '0';
        } else {
            output[i] = '1';
        }
    }
    int t = output.length();
    return output;
}

string encrypt(string plaintext, string key) {

    string pt_bin = str_to_bin(plaintext);
    cout<<"PlainText\n"<<pt_bin;

    string key_bin = str_to_bin(key);
    cout<<"\nKey  Text\n"<<key_bin<<endl;
    cout<<"XOR\n";

    return XOR(pt_bin, key_bin);
}

string decrypt(string ciphertext, string key) {

    string ct_bin = ciphertext;
    cout<<"\nCipherText\n"<<ct_bin;

    string key_bin = str_to_bin(key);
    cout<<"\nKey  Text\n"<<key_bin;
    cout<<"\nXOR\n";

    return XOR(ct_bin, key_bin);
}

int main()
{
    // No spaces
    cout<<encrypt("ARFAT", "ABCDE");
    cout<<endl<<decrypt("0000000000010000000001010000010100010001", "ABCDE");
    return 0;
}
