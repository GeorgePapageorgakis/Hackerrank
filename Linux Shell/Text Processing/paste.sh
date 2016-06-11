# The paste command is used for merging lines of a given file. It may be used for merging data from one or more files. 

# Replace the newlines in the input with tabs as demonstrated in the sample.
paste -s

# Given a CSV file where each row contains the name of a city and its state separated by a comma, your task is to restructure the file in such a way, that three consecutive rows are folded into one, and separated by tab. 
paste - - -
paste - - - -d'\t'

# You are given a CSV file where each row contains the name of a city and its state separated by a comma. Your task is to replace the newlines in the file with semicolons as demonstrated in the sample. 
paste -s -d';'

# Restructure the file so that three consecutive rows are folded into one line and are separated by semicolons. 
paste -d';' - - -