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

string permute(string plaintext, string table) {

    string permutedtext = plaintext;
    int table_offset = 0;

    for (int i = 0; i < plaintext.length(); i++) {

        int k = char_to_int(table[table_offset]) - 48; // because it will return ASCII value

        table_offset = (table_offset + 1) % table.length();

        //char temp = permutedtext[k-1];
        permutedtext[i] = plaintext[k-1];
        //permutedtext[i] = temp;
    }

    return permutedtext;
}


string _encrypt(string plaintext, string table, int col) {

    string intermediate = "";
    string ciphertext = plaintext;
    int pos = 0;
    //int rows = plaintext.length() / col;

    for (int i = 0; i < plaintext.length(); i += col) {
        intermediate += permute(plaintext.substr(i, col), table);
    }

    for (int i = 0; i < col; i++) {

        int j = i;

        while (j < plaintext.length()) {
            ciphertext[pos++] = intermediate[j];

            j += col;
        }
    }

    return ciphertext;
}

string encrypt(string plaintext, string table, int col) {
    return _encrypt(_encrypt(plaintext, table, col), table, col);
}

string _decrypt(string ciphertext, string table, int col) {

    string plaintext = ciphertext;
    string intermediate = "";

    int pos = 0;
    int new_col = ciphertext.length()/col;

    for (int i = 0; i < new_col; i++) {

        int j = i;

        while (j < plaintext.length()) {
            plaintext[pos++] = ciphertext[j];

            j += new_col;
        }
    }

    for (int i = 0; i < plaintext.length(); i += col) {
        intermediate += permute(plaintext.substr(i, col), table);
    }

    return intermediate;
}

string decrypt(string ciphertext, string table, int col) {
    return _decrypt(_decrypt(ciphertext, table, col), table, col);
}

int main()
{
    // Key should be smaller than 26 letters
    //cout<<encrypt("enemyattackstonight", 5);
    //cout<<encrypt("enemyattackstonightz", "31452", 5);
    cout<<decrypt("tiyteaozhmcseangtktn", "25134", 5);

    return 0;
}
