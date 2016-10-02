#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

bool is_lower(char ch) {
    if (ch >= 'a' && ch <= 'z') {
            return true;
    }
    return false;
}

int char_to_int(char ch)
{
    if ( ch >= 'A' && ch <= 'Z')
    {
        return (int)ch - 65;
    }
    else if (ch >= 'a' and ch <= 'z')
    {
        return (int)ch - 97;
    }
    else
    {
        return int(ch);
    }
}

char int_to_char(int ch, bool lower=false)
{
    if (ch >= 0 && ch <= 25)
    {
        if (lower)
        {
            return (char)(ch + 97);
        }

        return (char)(ch + 65);
    }
    else
    {
        return (char)ch;
    }

}


int mod(int i, int j) {
    if (i % j < 0) {
        return i+j;
    }
    return i % j;
}


int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return GCD(b, a%b);
    }
}

#endif // UTILS_H_INCLUDED
