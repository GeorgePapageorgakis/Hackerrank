# Output the first 20 lines of the given text file.
head -n 20

# Display the first 20 characters of an input file.
head -c 20

# Display the lines (from line number 12 to 22, both inclusive) for the input file. 
head -22 | tail -11	#can also use -n 22

# Display the last 20 lines of an input file.
tail -20
tail -n -20

# Display the last 20 characters of an input file.
tail -c 20