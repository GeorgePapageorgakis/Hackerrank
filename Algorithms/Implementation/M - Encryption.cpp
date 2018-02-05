/*
An English text needs to be encrypted using the following encryption scheme.
First, the spaces are removed from the text. Let L be the length of this text.
Then, characters are written into a grid, whose rows and columns have the following constraints:
	
    floor(L) <= row <= column <= ceil(L)

For example, the sentence if man was meant to stay on the ground god would have given us roots after removing spaces is 54 characters long, so it is written in the form of a grid with 7 rows and 8 columns. 

ifmanwas  
meanttos          
tayonthe  
groundgo  
dwouldha  
vegivenu  
sroots

    * Ensure that rows x columns >= L
    * If multiple grids satisfy the above conditions, choose the one with the minimum area, i.e. rows x columns.

The encoded message is obtained by displaying the characters in a column, inserting a space, and then displaying the next column and inserting a space, and so on. For example, the encoded message for the above rectangle is:

imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn sseoau 

haveaniceday:
have
anic
eday

hae and via ecy

feedthedog
feed
thed
og

fto ehg ee dd

chillout
chi
llo
ut

clu hlt io
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string encryptString (string str) {
	string encryptedStr = "";
	//remove all spaces from s
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	int rows = ( sqrt(str.length()) > floor(sqrt(str.length())) + 0.5 ? floor(sqrt(str.length())) + 1: floor(sqrt(str.length())) );
	int columns = ceil(sqrt(str.length()));
	
	for (i = 0; i < columns; ++i) {
		for (j = 0; j < rows; ++j) {
			if (str.at(columns*j + i) != " ") {
				encryptedStr += str.at(columns*j + i);
			}
		}
		encryptedStr += " ";
	}
	return encryptedStr;
}

int main(){
    string s;
    cin >> s;
	
	cout << encryptString(s);
    return 0;
}