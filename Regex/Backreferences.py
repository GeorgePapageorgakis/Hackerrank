# \group_number tool (\1 references the first capturing group) matches the same text as previously matched by the capturing group.
'''
For Example:
	(\d)\1: It can match 00, 11, 22, 33, 44, 55, 66, 77, 88 or 99.

Task:
	write a regex that will match SS with the following conditions:
		S must be of length: 20
		1st character: lowercase letter.
		2nd character: word character.
		3rd character: whitespace character.
		4th character: non word character.
		5th character: digit.
		6th character: non digit.
		7th character: uppercase letter.
		8th character: letter (either lowercase or uppercase).
		9th character: vowel (a, e, i , o , u, A, E, I, O or U).
		10th character: non whitespace character.
		11th character: should be same as 1st character.
		12th character: should be same as 2nd character.
		13th character: should be same as 3rd character.
		14th character: should be same as 4th character.
		15th character: should be same as 5th character.
		16th character: should be same as 6th character.
		17th character: should be same as 7th character.
		18th character: should be same as 8th character.
		19th character: should be same as 9th character.
		20th character: should be same as 10th character.
'''
Regex_Pattern = r'^([a-z])(\w)(\s)(\W)(\d)(\D)([A-Z])([a-zA-Z])([aeiouAEIOU])(\S)\1\2\3\4\5\6\7\8\9\10$'



# Capturing group that match nothing. Here, b? is optional and matches nothing.
'''
	(b?)o\1 captures o
Thus, (b?) is successfully matched and capture nothing.
o is matched with o and \1 successfully matches the nothing captured by the group.
'''

# Capturing group that didn't participate in the match at all
'''
	(b)?o\1 does NOT capture o
In most regex flavors (excluding JavaScript), (b)?o\1 fails to match o.
Here, (b) fails to match at all. Since, the whole group is optional the regex engine does proceed to match o.
The regex engine now arrives at \1 which references a group that did not participate in the match attempt at all.
Thus, the backreference fails to match at all.

Task:
write a regex which will match S, with following condition(s):
    S consists of 8 digits.
    S may have "−" separator such that string S gets divided in 4 parts, with each part having exactly two digits. (Eg. 12-34-56-78) and NOT (1-234-56-78) or (12-45-7810)
'''
Regex_Pattern = r"^(\d{2})(-?)(\d{2})\2(\d{2})\2(\d{2})$"
# backreferencing with \1 wont work cause if the third character is not "-", \1 won't exist. Hence, using \1 later would always fail the regex.



# (?|regex) branch reset group consists of alternations and capturing groups. (?|(regex1)|(regex2))		
# Note: only supported by Perl, PHP, Delphi and R.
'''
Alternatives in branch reset group share same capturing group. 
Example:
	(?|(Haa)|(Hee)|(bye)|(k))\1
	HaaHaa
	kk
	
	(?|(a)|(b)|(c)) consists of a single branch reset group with three alternatives. This regex matches either a, b, or c
	(?|(a)|(b)|(c))\1 matches aa, bb, or cc
	(?|abc|(d)(e)(f)|g(h)i) has three capturing groups. When this regex matches abc, all three groups are empty. When def is matched, $1 holds d, $2 holds e and $3 holds f. When ghi is matched, $1 holds h while the other two are empty.

Task:
write a regex which will match S, with following condition(s):
    S consists of 8 digits.
    S must have "---", "-", "." or ":" separator such that string S gets divided in 4 parts, with each part having exactly two digits.
    S string must have exactly one kind of separator.
    Separators must have integers on both sides.
	Valid:
		12-34-56-78
		12:34:56:78
		12---34---56---78
		12.34.56.78
	Not Valid:
		1-234-56-78
		12-45.78:10
'''
$Regex_Pattern = '^\d{2}(?|((\-{3})|(\-)|(\.)|(:)))\d{2}\1\d{2}\1\d{2}$';
or
$Regex_Pattern = '^\d{2}((\-{3}?)|(\-?)|(\.?)|(:?))\d{2}\1\d{2}\1\d{2}$';

$Test_String = <STDIN> ;
if($Test_String =~ /$Regex_Pattern/){
    print "true";
} else {
    print "false";
}
#important to notice that \1 is used to match the same type met in the first backreferencing.
#Hence, 12:34.56-78 wont match but only if all three are the same


#Forward reference creates a back reference to a regex that would appear later.
#Forward references are only useful if they're inside a repeated group.
#Then there may arise a case in which the regex engine evaluates the backreference after the group has been matched already.
'''
Example:
	(\2amigo|(go!))+
	go!go!amigo

Task:
write a regex which will match S, with following condition(s):
    S consists of tic or tac.
    tic should not be immediate neighbour of itself.
    The first tic must occur only when tac has appeared atleast twice before.
'''
$Regex_Pattern = '^(\2tic|(tac))+$';

$Test_String = <STDIN> ;
if($Test_String =~ /$Regex_Pattern/){
    print "true";
} else {
    print "false";
}
tactactictactictictac
false