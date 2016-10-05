#include <iostream>
#include "utils.h"

using namespace std;

int K[4][4] = {
                {9, 7, 11, 13},
                {4, 7, 5, 6},
                {2, 21, 14, 9},
                {3, 23, 21, 8}
            };

int K_inv[4][4] = {
                {2, 15, 22, 3},
                {15, 0, 19, 3},
                {9, 9, 3, 11},
                {17, 0, 4, 7}
            };


int P[10][10] = {0};
int C[10][10] = {0};

string format(string plaintext, int col) {


    if (plaintext.length() % col == 0) {
        return plaintext;
    }

    int bog_chr = col - (plaintext.length() % col);

    for (int i = 0; i < bog_chr; i++) {
        plaintext += "Z";
    }
    return plaintext;
}

int display_matrix(int A[][10], int row, int col) {
    cout<<endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout<<" "<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
int populate_matrix(string text, int row, int col) {

    int pos = 0;

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < col; j++) {
            int t = char_to_int(text[pos++]);
            P[i][j] = t;
        }
    }

    return 0;
}

int multiply_matrix(int P[][10], int row, int col, int K[][4], int row1, int col1) {

    int sum = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < col; k++) {
                int t1 = P[i][k];
                int t2 = K[k][j];
                sum = sum +  t1*t2 ;
            }
            int t = mod(sum, 26);
            C[i][j] = t;
            sum = 0;
        }
    }

    return 0;
}

string encrypt(string plaintext, int col) {

    if (col != 4) {
        cout<<"The Key is 4x4. Hence, the column of matrix should be 4\n";
        return "";

    }

    string intermediate = format(plaintext, col);
    int row = intermediate.length() / col;

    populate_matrix(format(plaintext, col), row, col);

    multiply_matrix(P, row, col, K, 4, 4);

    string ciphertext = "";

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            ciphertext += int_to_char(C[i][j]);
        }
    }

    return ciphertext;

}

string decrypt(string ciphertext, int col) {

    if (col != 4) {
        cout<<"The Key is 4x4. Hence, the column of matrix should be 4\n";
        return "";

    }

    int row = ciphertext.length() / col;

    populate_matrix(ciphertext, row, col);

    multiply_matrix(P, row, col, K_inv, 4, 4);

    string plaintext = "";

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            plaintext += int_to_char(C[i][j]);
        }
    }

    return plaintext;

}

int main()
{
    // You need to specify the Columns
    // Also, no spaces
    cout<<decrypt(encrypt("Codeisready", 4), 4);
    return 0;
}
