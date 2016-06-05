# regex_1(?=regex_2)
# The positive lookahead (?=) asserts regex_1 to be immediately followed by regex_2. The lookahead is excluded from the match. It does not return matches of regex_2. The lookahead only asserts whether a match is possible or not. 
'''
Example:
	c(?=o)
	cho(c)olate
	
Task:
	Write a regex that can match all occurrences of o followed immediately by oo in S.
'''
$Regex_Pattern = 'o(?=oo)';
$Test_String = <STDIN> ;
$count = () = $Test_String =~ /$Regex_Pattern/g;
print "Number of matches : ",$count ;


# regex_1(?!regex_2)
# The negative lookahead (?!) asserts regex_1 not to be immediately followed by regex_2. Lookahead is excluded from the match (do not consume matches of regex_2), but only assert whether a match is possible or not. 
'''
Example:
	c(?!o)
	(c)hocolate

Task:
	Write a regex which can match all characters which are not immediately followed by that same character.
	If S = goooo, then regex should match (g) ooo (o). Because the first g is not follwed by g and the last o is not followed by o.
	example: (g)ooo(o)
'''
$Regex_Pattern = '(.)(?!\1)';
$Test_String = <STDIN> ;
$count = () = $Test_String =~ /$Regex_Pattern/g;
print "Number of matches : ",$count ;


# (?<=regex_2)regex_1
# The positive lookbehind (?<=) asserts regex_1 to be immediately preceded by regex_2. Lookbehind is excluded from the match (do not consume matches of regex_2), but only assert whether a match is possible or not. 
'''
Example:
	(?<=[a-z])[aeiou]
	h(e)1o
Task:
	Write a regex which can match all the occurences of digit which are immediately preceded by odd digit.
'''
$Regex_Pattern = '(?<=[13579])\d';
$Test_String = <STDIN> ;
$count = () = $Test_String =~ /$Regex_Pattern/g;
print "Number of matches : ",$count ;


# (?<!regex_2)regex_1
# The negative lookbehind (?<!) asserts regex_1 not to be immediately preceded by regex_2. Lookbehind is excluded from the match (do not consume matches of regex_2), but only assert whether a match is possible or not.
'''
Example:
	(?<![a-z])[aeiou]
	he1(o)
Task:
	Write a regex which can match all the occurences of characters which are not immediately preceded by vowels (a, e, i, u, o, A, E, I, O, U).
'''
$Regex_Pattern = '(?<![aeiuoAEIOU]).';
$Test_String = <STDIN> ;
$count = () = $Test_String =~ /$Regex_Pattern/g;
print "Number of matches : ",$count ;
