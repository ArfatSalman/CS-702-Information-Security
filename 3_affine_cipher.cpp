#include <iostream>
#include "utils.h"

using namespace std;

int multiplicative_inverse(int z_n, int b) {
    if (GCD(z_n, b) != 1) {
        return -1;
    }

    int t1 = 0, t2 = 1;
    int n = z_n;

    while ( b > 0) {
        int quot = n/b;

        int r = n - quot * b;
        n = b;
        b = r;

        int t = t1 - quot*t2;
        t1 = t2;
        t2 = t;
    }

    if (t1 < 0) {
        t1 = t1 + z_n;
    }
    return t1;
}

string encrypt(string pt, int key1, int key2) {

    if (multiplicative_inverse(26, key1) == -1) {
        cout<<"Multiplicative Inverse of "<<key1<<" does not exist. \n Can't encrypt.\n";
        return "";
    }

    string encryptedString = pt;
    bool lower = false;

    key1 = key1 % 26; // Since it is working on English letters
    key2 = key2 % 26;

    for (unsigned int i = 0; i < pt.length(); i++) {

        lower = is_lower((char)pt[i]);

        int ch = char_to_int((char)pt[i]);

        if (ch >= 0 && ch < 26) {
            ch = (ch * key1) % 26;
            ch = (ch + key2) % 26;
        }

        encryptedString[i] = int_to_char(ch, lower);
    }

    return encryptedString;
}

string decrypt(string ct, int key1, int key2) {
    int inv = multiplicative_inverse(26, key1);

    if (inv == -1) {
        cout<<"Multiplicative Inverse of "<<key2<<" does not exist. \n Can't decrypt.\n";
        return "";
    }

    string decryptedString = ct;
    key1 = key1 % 26;
    key2 = key2 % 26;
    bool lower = false;

    for (unsigned int i = 0; i < ct.length(); i++) {

        lower = is_lower((char)ct[i]);

        int ch = char_to_int((char)ct[i]);

        if (ch >= 0 && ch < 26) {
            ch = (ch - key2) % 26;s
            ch = (ch * inv) % 26;


            if (ch < 0) {
                ch = ch + 26; // Since after subtraction ch can be negative
                // and -7 % 26 = 26 - 7 = 19 instead of -7
            }
        }

        decryptedString[i] = int_to_char(ch, lower);
    }

    return decryptedString;

}

int main()
{
    cout<<decrypt("Zebbw;;';.", 7, 2);
    return 0;
}
