#Regex String Matching 


import re
#match  xxx.xxx.xxx.xxx.
Regex_Pattern = r"...\....\....\...."	# Do not delete 'r'.

Test_String = input()
match = re.findall(Regex_Pattern, Test_String)
print("Number of matches :", len(match))


# The dot (.) matches anything (except for a newline).
# To match (.) in the test string, you need to escape the dot by using a slash \.
# In Java and C++, use \\. instead of \. 


# The expression \d matches any digit [0 - 9].
# The expression \D matches any character that is not a digit.


# The \s matches any whitespace character [ \r\n\t\f]
# The \S matches any non-white space character.


# The expression \w will match any word character.
# Word characters include alphanumeric characters (a-z, A-Z and 0-9) and underscores (_).
# The \W matches any non-word character.
# Non-word characters include characters other than alphanumeric characters (a-z, A-Z and 0-9) and underscore (_).


# The ^ symbol matches the position at the start of a string.
# The $ symbol matches the position at the end of a string.


'''
You have a test string S. Your task is to match the pattern Xxxxx.
Here, x denotes a word character, and X denotes a digit.
S must start with a digit X and end with . symbol.
S should be 6 characters long only.
'''
import re
Regex_Pattern = r"^\d\w\w\w\w\.$"
print(str(bool(re.search(Regex_Pattern, input()))).lower())

'''
"Text" can be almost any character. Importantly, it can also include spaces.
    Text
    Text 01
    Text 01 of 03
    Text 01 (of 03)
    Text 01-03
I'd like to capture "Text", "01", and "03" as separate groups, and all except "Text" are optional. 

$re = '/ # Always write non-trivial regex in free-space mode!
    ^                  # Anchor to start of string.
    \s*                # optional leading whitspace is ok.
    (.+?)              # Text can be pretty much anything.
    (?:                # Group to allow applying ? quantifier
      \s+              # WS separates "Text" from first number.
      (\d+)            # First number.
      (?:              # Group to allow applying ? quantifier
        (?:            # Second number prefix alternatives
          \s+\(?of\s+  # Either " of 03" and " (of 03)",
        | -            # or just a dash  for "-03" case.
        )              # End second number prefix alternatives
        (\d+)          # Second number
        \)?            # Match ")" for " (of 03)" case.
      )?               # Second number is optional.
    )?                 # First numebr is optional.
    $                  # Anchor to start of string.
    /ix';
'''