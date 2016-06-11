# -d option only prints those lines that are followed by one or more repetitions immediately after them
# -u option only prints those lines that are succeeded and preceded by different lines
# Other possible options:
#    - Limit comparison only to the first characters (using the -w option).
#    - Avoid comparing the first characters (using the -s option).
#    - Ignore variations in case between lines (using the -i option).
#    - Avoid comparing the first fields (using the -f option).
#      (This may be useful while processing TSV files when you'd like to ignore the first column if it has serial numbers.)
#
# Given a text file, remove the consecutive repetitions of any line.
uniq

# Given a text file, count the number of times each line repeats itself. Only consider consecutive repetitions. Display the space separated count and line, respectively. There shouldn't be any leading or trailing spaces. Please note that the uniq -c command by itself will generate the output in a different format than the one expected here. 
uniq -c | sed -e 's/^[ \t]*//'
#    s/ : Substitute command ~ replacement for pattern (^[ \t]*) on each addressed line
#    ^[ \t]* : Search pattern ( ^ – start of the line; [ \t]* match one or more blank spaces including tab)
#    // : Replace (delete) all matched pattern
or
uniq -c | cut -c7-

#This time, compare consecutive lines in a case insensitive manner. So, if a line X is followed by case variants, the output should count all of them as the same (but display only the form X in the second column).

#So, as you might observe in the case below: aa, AA and Aa are all counted as instances of 'aa'. 
uniq -c -i | cut -c7-

# Given a text file, display only those lines which are not followed or preceded by identical replications.
uniq -u