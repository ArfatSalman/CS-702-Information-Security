#include <iostream>
#include <math.h>
#include "utils.h"

using namespace std;

int multiplicative_inverse(int z_n, int b) {
    // Using Extended Euclidean Algorithm
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


int CRT(int a, int b, int p, int q) {
    // x --- a mod p
    // x --- b mod q

    if (GCD(p, q) == 1) {

        int M = p * q;

        int p_inv = multiplicative_inverse(q, p);
        int q_inv = multiplicative_inverse(p, q);

        return mod(a*q*q_inv + b*p*p_inv, M);
    }

    return -1;

}

int int_pow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
           result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}

int encrypt(int p, int key) {
    if (GCD(p, key) == 1) {
        return (p*p) % key;
    }
    return -1;
}

int decrypt(int c, int p, int q) {
    int a1 = mod( int_pow(c, (p+1)/4), p);
    int a2 = mod(-int_pow(c, (p+1)/4), p);
    int b1 = mod( int_pow(c, (q+1)/4), q);
    int b2 = mod(-int_pow(c, (q+1)/4), q);

    cout<<"\nThe result is: "<<CRT(a1, b1, p, q);
    cout<<"\nThe result is: "<<CRT(a1, b2, p, q);
    cout<<"\nThe result is: "<<CRT(a2, b1, p, q);
    cout<<"\nThe result is: "<<CRT(a2, b2, p, q);

    return 0;
}

int main()
{
    cout<<"Not For Large Values. Since INT does not support more than ~2^31\n";
    cout<<encrypt(10, 77);

    decrypt(23, 7, 11);
    return 0;
}
