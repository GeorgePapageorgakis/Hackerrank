# The tool {x} will match exactly x repetitions of character/character class/groups.

'''
Example: 
	\w{4}
	w{3} : match the character w exactly 33 times.
	[xyz]{5} : match the string of length 5 consisting of characters {x, y, z}. For example it will match xxxxx, xxxyy and xyxyz.
	\d{4} : It will match any digit exactly 4 times.

You have a test string S.
Your task is to write a regex that will match SS using the following conditions:
    S must be of length equal to 45.
    The first 40 characters should consist of letters(both lowercase and uppercase), or of even digits.
    The last 5 characters should consist of odd digits or whitespace characters.
'''
Regex_Pattern = r'^[a-zA-Z02468]{40}[13579\s]{5}$'


# The {x,y} tool will match between x and y (both inclusive) repetitions of character/character class/group.

'''
Example:
	w{3,5} : It will match the character w 3, 4 or 5 times.
	[xyz]{5,} : It will match the character x, y or z 5 or more times.
	\d{1, 4} : It will match any digits 1, 2, 3 or 4 times.

Task:
You have a test string SS.
Your task is to write a regex that will match S using the following conditions:
    S should begin with 1 or 2 digits.
    After that, SS should have 3 or more letters (both lowercase and uppercase).
    Then S should end with up to 3 . symbol(s). You can end with 0 to 3 . symbol(s), inclusively.
'''
Regex_Pattern = r'^\d{1,2}[a-zA-Z]{3,}\.{0,3}$'

# The * tool will match zero or more repetitions of character/character class/group.

'''
For Example:
	w* : It will match the character w 0 or more times.
	[xyz]* : It will match the characters x, y or z 0 or more times.
	\d* : It will match any digit 0 or more times. 
	Task

Task:
Your task is to write a regex that will match S using the following conditions:
    S should begin with 2 or more digits.
    After that, S should have 0 or more lowercase letters.
    S should end with 0 or more uppercase letters
'''
Regex_Pattern = r'^\d\d\d*[a-z]*[A-Z]*$'


# The + tool will match one or more repetitions of character/character class/group.

'''
For Example:
	w+ : It will match the character w 1 or more times.
	[xyz]+ : It will match the character x, y or z 1 or more times.
	\d+ : It will match any digit 1 or more times.

Task:
Your task is to write a regex that will match S using the following conditions:
    S should begin with 1 or more digits.
    After that, S should have 1 or more uppercase letters.
    S should end with 1 or more lowercase letters.
'''
Regex_Pattern = r'^\d+[A-Z]+[a-z]+$'


# The $ boundary matcher matches an occurrence of a character/character class/group at the end of a line.

'''
For Example:
	\w*s$ Maches any number of word characters and ends with s.
	
Task:
Write a RegEx to match a test string, S, under the following conditions:
    S should consist of only lowercase and uppercase letters (no numbers or symbols).
    S should end in s.
'''
Regex_Pattern = r'^[a-zA-Z]*s$'
