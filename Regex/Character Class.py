# The character class [ ] matches only one out of several characters placed inside the square brackets.
'''
You have a test string S.
Your task is to write a regex that will match SS with following conditions:

    S must be of length: 6
    First character: 1, 2 or 3
    Second character: 1, 2 or 0
    Third character: x, s or 0
    Fourth character: 3, 0 , A or a
    Fifth character: x, s or u
    Sixth character: . or ,
'''
import re
Regex_Pattern = r'^[123][120][xs0][30Aa][xsu][.,]$'	# Do not delete 'r'.
print(str(bool(re.search(Regex_Pattern, input()))).lower())



# Τhe negated character class [^] matches any character that is not in the square brackets.
'''
You have a test string S.
Your task is to write a regex that will match SS with the following conditions:

    S must be of length 6.
    First character should not be a digit ( 1,2,3,4,5,6,7,8,9 or 0 ).
    Second character should not be a lowercase vowel ( a,e,i,o or u ).
    Third character should not be b, c, D or F.
    Fourth character should not be a whitespace character ( \r, \n, \t, \f or <space> ).
    Fifth character should not be a uppercase vowel ( A,E,I,O or U ).
    Sixth character should not be a . or , symbol.
'''
Regex_Pattern = r'^[^\d][^aeiou][^bcDF][^\s][^AEIOU][^.,]$'



# A hyphen inside a character class specifies a range of characters. For example:
#
#    [a−z] is the same as [abcdefghijklmnopqrstuvwxyz].
#    [A−Z] is the same as [ABCDEFGHIJKLMNOPQRSTUVWXYZ].
#    [0−9] is the same as [0123456789].

'''
You have a test string S.
Your task is to write a regex that will match SS using the following conditions:

    S must be of length, greater than or equal to 5.
    First character should be a lowercase alphabet.
    Second character should be a positive digit.
    Third character should not be a lowercase alphabet.
    Fourth character should not be a uppercase alphabet.
    Fifth character should be an uppercase alphabet.
'''
Regex_Pattern = r'^[a-z][1-9][^a-z][^A-Z][A-Z]'


