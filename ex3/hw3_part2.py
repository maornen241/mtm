
from pickletools import read_uint1


def is_palindrom(s):
    if s == "":
        return False

    s_fliped = s[-1:-len(s)-1:-1]
    return (s == s_fliped)



def get_palindrom_dict(str):
    palindroms = {}

    str_len = len(str)
    for sub_len in range(1, str_len+1):
        for start in range(str_len-sub_len + 1): 
            sub_str = str[start:start+sub_len]

            if(is_palindrom(sub_str)):

                if( not(sub_len in palindroms.keys()) ):
                    palindroms[sub_len] = [sub_str, ]

                else:
                    (palindroms[sub_len]).append(sub_str)
    
    return palindroms


def check_match(str):
    if len(str) == 0:
        return True

    if (len(str))%2 == 1:
        return False

    chars_match = {}
    for start in range(0,len(str)-1, 2):
        from_char = str[start]
        to_char = str[start+1]

        if ( from_char in chars_match.keys() ) and ( to_char != chars_match[ from_char ] ):
            return False
        
        elif not ( from_char in chars_match.keys() ):
            chars_match[from_char] = to_char
    
    return True

            


   
    