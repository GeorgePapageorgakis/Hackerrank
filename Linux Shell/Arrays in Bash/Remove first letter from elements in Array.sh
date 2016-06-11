# You are given a list of countries, each on a new line. Your task is to read them into an array and then transform them in the following way:

# The first capital letter (if present) in each element of the array should be replaced with a dot ('.'). Then, display the entire array with a space between each country's names.
arr=($(cat))
echo ${arr[@]/[A-Z]/.}		
#this may transform niGeria -> ni.eria
#${arr[@]/#[A-Z]/.} to restrict check for only first char of each element

# or bash only

{ a=($(cat)); echo ${a[@]/?/.}; }

# or without arrays

sed 's/^[A-Z]/./'|paste -s

#or 

arr=((cat)){arr[@]/[A-Z]/.}