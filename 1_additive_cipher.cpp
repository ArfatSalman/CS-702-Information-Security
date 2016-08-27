#include <iostream>

using namespace std;

int char_to_int(char ch)
{
    if ( ch >= 'A' && ch <= 'Z')
    {
        return (int)ch - 65 + 1;
    }
    else if (ch >= 'a' and ch <= 'z')
    {
        return (int)ch - 97 + 1;
    }
    else
    {
        return int(ch);
    }
}

char int_to_char(int ch, bool lower=false)
{
    if (ch > 0 && ch <= 26)
    {
        if (lower)
        {
            return (char)(ch + 97 - 1);
        }

        return (char)(ch + 65 - 1);
    }
    else
    {
        return (char)ch;
    }

}

string encrypt(string st, int cipher=0)
{
    string encryptedString = st;
    int ch;
    bool lower = false;
    cipher =cipher % 26;

    for (int i = 0; i<st.length(); i++) {
        if ((char)st[i] >= 'a' && (char)st[i]<='z') {
            lower = true;
        }

        ch = char_to_int((char)st[i]);

        if (ch <= 26) {
            ch = (ch + cipher) % 26;
            if (ch == 0) ch = 26;
        }

        char c = int_to_char(ch, lower);
        encryptedString[i] = c;
    }
    return encryptedString;
}

string decrypt(string st, int cipher) {
    string decryptedString = st;
    int ch;
    bool lower = false;
    cipher =cipher % 26;

    for (int i = 0; i<st.length(); i++) {
        if ((char)st[i] >= 'a' && (char)st[i]<='z') {
            lower = true;
        } else {
            lower = false;
        }

        ch = char_to_int((char)st[i]);

        if (ch <= 26) {
            ch = (ch - cipher) % 26;
            if (ch < 0) {
                ch = ch + 26;
            }
            if (ch == 0) ch = 26;
        }

        char c = int_to_char(ch, lower);
        decryptedString[i] = c;
    }
    return decryptedString;
}

int main()
{
    cout<<decrypt(encrypt("ABCDEFGHIjklmnopqrstuvwxys..;;'[]'.,", 15), 15)<<endl;
    cout<<decrypt(encrypt("ABCDEFGHIjklmnopqrstuvwxys;;';';", 7), 7)<<endl;
    cout<<decrypt(encrypt("ABCDEFGHIjklmnopqrstuvwxys;;;;''''", 250), 250);
    return 0;
}
