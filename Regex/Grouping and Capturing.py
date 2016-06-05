# \b assert position at a word boundary.
'''
Three different positions qualify for word boundaries :
	► Before the first character in the string, if the first character is a word character.
	► Between two characters in the string, where one is a word character and the other is not a word character.
	► After the last character in the string, if the last character is a word character.

Task:
	Write a regex which will match word starting with vowel (a,e,i,o, u, A, E, I , O or U).
	The matched word can be of any length. The matched word should consist of letters (lowercase and uppercase both) only.
	The matched word must start and end with a word boundary.
'''
Regex_Pattern = r'\b[aeiouAEIOU][A-Za-z]*\b'


# Parenthesis ( ) around a regular expression can group that part of regex together. This allows us to apply different quantifiers to that group.
# These parenthesis also create a numbered capturing. It stores the part of string matched by the part of regex inside parentheses.
#These numbered capturing can be used for backreferences. ( We shall learn about it later )

# (?: ) can be used to create a non-capturing group. It is useful if we do not need the group to capture its match.
'''
For instance (?:Bob|Chloe) matches Bob or Chloe—but the name is not captured.

Within a non-capturing group, you can still use capture groups. 
For instance, (?:Bob says: (\w+)) would match Bob says: Go and capture Go in Group 1.

Likewise, you can capture the content of a non-capturing group by surrounding it with parentheses. 
For instance, ((?:Bob|Chloe)\d\d) would capture "Chloe44".

Task:
	Write a regex which will match S with the following condition:
    S should have 3 or more consecutive repetitions of ok.
'''
Regex_Pattern = r'(ok){3,}'


# Alternations ( | ), matches single regular expression out of several possible regexes. It matches either everything to the left or everything to the right of the vertical bar. We need to use parenthesis to limit the use of alternations.
'''
For example :
	(Bob|Kevin|Stuart) : It will match either Bob or Kevin or Stuart.
	([a-f]|[A-F]) : It will match a, b, c, d, e, f, A, B, C, D, E or F. 

Task:
	Write a regex which will match S with following conditions:
    S must start with Mr., Mrs., Ms., Dr. or Er..
    And after that it must be followed by one or more letters (lowercase and uppercase both) only.
'''
Regex_Pattern = r'^(Mr\.|Mrs\.|Ms\.|Dr\.|Er\.)[A-Za-z]+$'
