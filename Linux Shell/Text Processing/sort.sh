#The sort command is frequently used for sorting input in text or TSV formats in various different ways. These ways may be #either lexicographical, case insensitive, based on the numeric field only, based on a particular column, etc.
#
#Sort Options
#
#    The vanilla sort command simply sorts the lines of the input file in lexicographical order.
#    -n option sorts the file on the basis of the numeric fields available if the first word or column in the file is a number.
#    -r option reverses the sorting order to either the reverse of the usual lexicographical ordering or descending order while sorting in numerical mode.
#    -k option is useful while sorting a table of data (tsv, csv etc.) based on a specified column (or columns).
#    -t option is used while specifying a delimiter in a particular file where columns are separated by tabs, spaces, pipes etc.
#
#  Given a text file, order the lines in lexicographical order. 
sort

#  Given a text file, order the lines in reverse lexicographical order (i.e. Z-A instead of A-Z).
sort -r

# You are given a text file where each line contains a number. 
# The numbers may be either an integer or have decimal places. 
# There will be no extra characters other than the number or the newline at the end of each line. 
# Sort the lines in ascending order - so that the first line holds the numerically smallest number, and the last line holds the numerically largest number.
sort -n

# Sort the lines in descending order - - such that the first line holds the (numerically) largest number and the last line holds the (numerically) smallest number.
sort -n -r

# You are given a file of text,which contains temperature information about American cities, in TSV (tab-separated) format. The first column is the name of the city and the next four columns are the average temperature in the months of Jan, Feb, March and April (see the sample input). Rearrange the rows of the table in descending order of the values for the average temperature in January. 
# reverse sorting based on the third numerical key
sort -r -n -k 2 -t$'\t'
or
sort -rnk 2 -t$'\t'
or
sort -t$'\t' -k2,2 -nr	
#k is for which column to use for sorting. k stands for key(Column no. to specify it takes value as -ka,b where sorting is from a to b comlumns)
or
sort -t$'\t' -k2 -nr

# You are given a file of tab separated weather data (TSV). There is no header column in this data file.
# The first five columns of this data are: (a) the name of the city (b) the average monthly temperature in Jan (in Fahreneit). (c) the average monthly temperature in April (in Fahreneit). (d) the average monthly temperature in July (in Fahreneit). (e) the average monthly temperature in October (in Fahreneit).

# You need to sort this file in ascending order of the second column (i.e. the average monthly temperature in January).
sort -t$'\t' -k2 -n

#You are given a file of pipe-delimited weather data (TSV). There is no header column in this data file. The first five columns of this data are: (a) the name of the city (b) the average monthly temperature in Jan (in Fahreneit). (c) the average monthly temperature in April (in Fahreneit). (d) the average monthly temperature in July (in Fahreneit). (e) the average monthly temperature in October (in Fahreneit).

#You need to sort this file in descending order of the second column (i.e. the average monthly temperature in January). 
sort -t$'|' -nrk2