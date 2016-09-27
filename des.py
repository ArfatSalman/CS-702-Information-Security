import pdb
init_perm = [58, 50, 42, 34, 26, 18, 10, 2,
             60, 52, 44, 36, 28, 20, 12, 4,
             62, 54, 46, 38, 30, 22, 14, 6,
             64, 56, 48, 40, 32, 24, 16, 8,
             57, 49, 41, 33, 25, 17, 9, 1,
             59, 51, 43, 35, 27, 19, 11, 3,
             61, 53, 45, 37, 29, 21, 13, 5,
             63, 55, 47, 39, 31, 23, 15, 7]

final_perm = [40, 8, 48, 16, 56, 24, 64, 32,
              39, 7, 47, 15, 55, 23, 63, 31, 
              38, 6, 46, 14, 54, 22, 62, 30,
              37, 5, 45, 13, 53, 21, 61, 29, 
              36, 4, 44, 12, 52, 20, 60, 28,
              35, 3, 43, 11, 51, 19, 59, 27, 
              34, 2, 42, 10, 50, 18, 58, 26,
              33, 1, 41, 9, 49, 17, 57, 25]

expa_dbox = [32, 1, 2, 3, 4, 5, 
             4, 5, 6, 7, 8, 9,
             8, 9, 10, 11, 12, 13, 
             12, 13, 14, 15, 16, 17,
             16, 17, 18, 19, 20, 21,
             20, 21, 22, 23, 24, 25, 
             24, 25, 26, 27, 28, 29, 
             28, 29, 30, 31, 32, 1]

straight_perm = [16, 7, 20, 21, 29, 12, 28, 17,
                1, 15, 23, 26, 5, 18, 31, 10,
                2, 8, 24, 14, 32, 27, 3, 9,
                19, 13, 30, 6, 22, 11, 4, 25]

parity_drop = [57, 49, 41, 33, 25, 17, 9, 1,
               58, 50, 42, 34, 26, 18, 10, 2, 
               59, 51, 43, 35, 27, 19, 11, 3,
               60, 52, 44, 36, 63, 55, 47, 39, 
               31, 23, 15, 7, 62, 54, 46, 38, 
               30, 22, 14, 6, 61, 53, 45, 37, 
               29, 21, 13, 5, 28, 20, 12, 4]

compress_dbox = [14, 17, 11, 24, 1, 5, 3, 28,
                 15, 6, 21, 10, 23, 19, 12, 4, 
                 26, 8, 16, 7, 27, 20, 13, 2,
                 41, 52, 31, 37, 47, 55, 30, 40,
                 51, 45, 33, 48, 44, 49, 39, 56, 
                 34, 53, 46, 42, 50, 36, 29, 32]

sbox1 = [
            [14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7],
            [0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8],
            [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0],
            [15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13] 
        ]

sbox2 = [
            [15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10],
            [3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5],
            [0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15],
            [13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9]
        ]

sbox3 = [
            [10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8], 
            [13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1], 
            [13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7], 
            [1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12]
        ]

sbox4 = [
            [7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15],
            [13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9],
            [10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4],
            [3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14]
        ]

sbox5 = [
            [2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9],
            [14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6],
            [4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14],
            [11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3]
        ]

sbox6 = [
            [12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11],
            [10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8],
            [9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6],
            [4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13]
        ]

sbox7 = [
            [4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1], 
            [13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6],
            [1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2], 
            [6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12]
        ]

sbox8 = [
            [13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7], 
            [1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2],
            [7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8],
            [2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11]

        ]

def perm(a, perm_list):
    out = []
    for x in perm_list:
        out.append(a[x-1])
    return "".join(out)

def xor(a, b):
    a = pad(a)
    b = pad(b)

    out = []
    for i in list(range(0, len(a))):
        if a[i] == '1' and b[i] == '1':
            out.append('0')
        elif a[i] == '0' and b[i] == '0':
            out.append('0')
        else:
            out.append('1')
    return "".join(out)

def pad(a):
    if len(a) % 4 == 0:
        return a

    to_pad =  4 - (len(a) % 4)

    for x in list(range(0, to_pad)):
        a = '0' + a

    return a

def keygen(a):
    
    a = perm(a, parity_drop)

    vals = into_x(a, 28) # 56 bit

    # l = int(vals[0], base=2)
    # r = int(vals[1], base=2)

    l = vals[0]
    r = vals[1]

    KEYS = []

    out = ''
    
    for x in list(range(1, 17)):

        if x in [1, 2, 9, 16]:
            f = l[0]
            l = l[1:] + f

            f = r[0]
            r = r[1:] + f

            # l = l << 1
            # r = r << 1
        else:
            f = l[0:2]
            l = l[2:] + f

            f = r[0:2]
            r = r[2:] + f

            # l = l << 2
            # r = r << 2
        out = l + r

        KEYS.append(perm(out, compress_dbox))

    #out = bin(l)[2:] + bin(r)[2:]
    out = l + r

    return KEYS

def into_x(a, x):
    return [a[i:i+x] for i in list(range(0, len(a), x))]

def sbox(a, sb):
    row = a[0] + a[-1]
    col = a[1:5]

    print ('Row: ', row, 'Col: ', col)

    return pad(bin(sb[int(row, base=2)][int(col, base=2)])[2:])

def all_sbox(l, r, key):
    print('L: ', into_x(l, 4))
    print('R: ', into_x(r, 4))
    # a is of 32 bits
    sboxes = [sbox1, sbox2, sbox3, sbox4, sbox5, sbox6, sbox7, sbox8]

    exp = perm(pad(r), expa_dbox)
    print('Expanding r')
    print('Exp: ', into_x(exp, 6))
    print('Key: ', into_x(key, 6))

    exp = xor(exp, key)
    print('XOR: ', into_x(exp, 6))

    vals = into_x(exp, 6)

    out = []
    print('sboxes')
    for i in list(range(0, 8)):
        t = sbox(vals[i], sboxes[i])
        print ('Val: ', t)
        out.append(t)

    print('sbox: ', into_x("".join(out), 4))
    print('final perm')
    out = perm("".join(out), straight_perm)

    print('sbox: ', into_x(out, 4))
    print('xoring with l')
    print('Left: ', into_x(l, 4))
    print('xorl: ', into_x(xor(pad(l), out), 4) ) 
    
    return xor(pad(l), out)

def to_hex(a):
    return hex(int(a, base=2))

def DES(ct, key, decrypt=False):
    print('Message: ', hex(ct))
    print('Key: ', hex(key))

    keys = keygen(pad(bin(key)[2:]))
    if decrypt:
        print('Decrypting ...')
        keys = keys[::-1]
    #keys = keys_1[::-1]

    txt = pad(bin(ct)[2:])
    print('Init: ', into_x(txt, 4))
    txt = perm(txt, init_perm)
    print('Perm: ', into_x(txt, 4))

    l_old, r = into_x(txt, 32)
    l = None

    print('L: ',hex(int(l_old, base=2)), ' R: ', hex(int(r, base=2)))
    
    for x in list(range(0, 16)):
        print('\n\nRound ', x+1)

        l = r

        r = all_sbox(l_old, r, keys[x])
        print('L: ', hex(int(l, base=2)), ' R: ', hex(int(r, base=2)), 'Key: ', hex(int(keys[x], base=2)))
        l_old = l

    print('Fin: ', into_x(r+l, 4))
    print('Final_perm: ',into_x(perm(r+l, final_perm), 4))
    return print(to_hex(perm(r+l, final_perm))) # because round 16 does not have a swapper


k = 0xaabb09182736ccdd
a = 0xc0b7a8d05f3a829c

if __name__ == '__main__':
    DES(a, k, True)