/*
When you select a contiguous block of text in a PDF viewer, the selection is highlighted with a blue rectangle. In a new kind of PDF viewer, the selection of each word is independent of the other words; this means that each rectangular selection area forms independently around each highlighted word.

In this type of PDF viewer, the width of the rectangular selection area is equal to the number of letters in the word times the width of a letter, and the height is the maximum height of any letter in the word.

Consider a word consisting of lowercase English alphabetic letters, where each letter is 1mm wide. Given the height of each letter in millimeters (mm), find the total area that will be highlighted by blue rectangle in mm^2 when the given word is selected in our new PDF viewer.

Constraints:
	1 <= h_i <= 7 where i is the English lowercase letter
	Word contains no more than 10 letters.

Sample Input 0
1 3 1 3 1 4 1 3 2 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
abc

Sample Output 0
9

Sample Input 1
1 3 1 3 1 4 1 3 2 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 7
zaba

Sample Output 1
28

*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int calcAreaHighlighted (vector<int> h, string word) {
	int width = word.length();
	int height = 0;
	//remove duplicates from word
	std::sort(word.begin(), word.end());
	word.erase(std::unique(word.begin(), word.end()), word.end());
	//find maximum lowercase char height
	for (auto &i : word ){
		//convert char to int h index, (only lowercase for this problem)
		int charIdx = int(i) - 97;
		if ( h[charIdx] > height){
			height = h[charIdx];
		}	
	}
	return width * height;
}

int main(){
    vector<int> h(26);
    for(int h_i = 0; h_i < 26; h_i++){
       cin >> h[h_i];
    }
    string word;
    cin >> word;
	
	cout << calcAreaHighlighted (h, word);
    return 0;
}