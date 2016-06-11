#'tr' command is a useful translation utility in linux. 

# In a given fragment of text, replace all parentheses() with box brackets []. 
tr "(" "[" | tr ")" "]"

# In a given fragment of text, delete all the lowercase characters a - z.
tr -d [a-z]

# In a given fragment of text, replace all sequences of multiple spaces with just one space.
tr -s " "  
# or 
tr -s ' ' ''
# s Replaces instances of repeated characters with a single character.