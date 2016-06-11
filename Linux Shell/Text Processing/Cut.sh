# Given N lines of input, print the 3rd character from each line as a new line of output. It is guaranteed that each of the n lines of input will have a 3rd character.
cut -c3

# Display the 2nd and 7th character from each line of text. 
cut -c2,7

# Display a range of characters starting at the 2nd position of a string and ending at the 7th position (both positions included).
cut -c2-7

# Display the first four characters from each line of text. 
cut -c-4

#Given a tab delimited file with several columns (tsv format) print the first three fields.
cut -f1-3

# Print the characters from thirteenth position to the end.
cut -c13-

# Given a sentence, identify and display its fourth word. Assume that the space (' ') is the only delimiter between words. 
cut -f4 -d" "

# Given a sentence, identify and display its first three words. Assume that the space (' ') is the only delimiter between words.
cut -f-3 -d" "

# Given a tab delimited file with several columns (tsv format) print the fields from second fields to last field.
cut -f2-