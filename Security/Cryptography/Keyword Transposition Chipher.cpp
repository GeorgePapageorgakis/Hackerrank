/*

A keyword transposition cipher is a method of choosing a monoalphabetic substitution to encode a message. The substitution alphabet is determined by choosing a keyword, arranging the remaining letters of the alphabet in columns below the letters of the keyword, and then reading back the columns in the alphabetical order of the letters of the keyword.
Traditionally, mixed alphabets may be created by first writing out a keyword, removing repeated letters in it, then writing all the remaining letters in the alphabet in the usual order.

Using this system, the keyword "zebras" gives us the following alphabets:
	Plaintext alphabet: 	ABCDEFGHIJKLMNOPQRSTUVWXYZ
	Ciphertext alphabet: 	ZEBRASCDFGHIJKLMNOPQTUVWXY

The keyword will be, at most, 7 characters long, and the ciphertext will be, at most, 255 characters in length (all uppercase).
SPORT
LDXTW KXDTL NBSFX BFOII LNBHG ODDWN BWK

SPORT
ABCDE
FGHIJ
KLMNQ
UVWXY
Z

since SPORT is OPRST in order, we read columns as:

01234 56789
OCHMW PBGLV RDINX SAFKUZ TEJQY
ABCDE FGHIJ KLMNO PQRSTU VWXYZ

LDXTW ILOVE		L=I D=L X=O T=V W=E 
KXDTL SOLVI 	K=S X=O D=L T=V L=I
NBSFX NGPRO 	...
BFOII GRAMM 
LNBHG INGCH 
ODDWN ALLEN 
BWK GES
CRYPT OLOGY
*/
#include <set>
#include <sstream>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Given a piece of ciphertext and the keyword used to encipher it, output the original message with the keyword transposition cipher described above.
*/
string keywordTranspositionCipher(string& keyword, string& text){
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result, newAlphabet = "", tmp = "";
    set<char> aux;
    
    //remove duplicate letters from keyword and store @temp
    //eg: SPORT -> SPORT, SECRET -> SECRT...
    set<char> t_set;
    remove_copy_if(keyword.begin(), keyword.end(), back_inserter(tmp), 
                        [&t_set](int x){ return !t_set.insert(x).second; });

    //transform keyword into ordered set of chars
    //eg: SPORT -> OPRST, SECRT -> CERST
    for(auto& k : keyword) aux.insert(k);
    
    //calculate new alphabet according to ordered set of chars
    //copy characters not present in aux to the alphabet to tmp
    //eg: SPORT ABCDE FGHIJ KLMNQ UVWXY Z
    for(string::iterator ch=alphabet.begin(); ch!=alphabet.end(); ++ch){
        if (!aux.count(*ch))
            tmp += *ch;         
    }
    //copy each char, according to the order of chars in aux, 
    //with index multiple of aux.size() to newAlphabet
    for(set<char>::iterator ch=aux.begin(); ch!=aux.end(); ++ch){
        int idx;
        idx = distance(tmp.begin(), find(tmp.begin(), tmp.end(), *ch));
        while(idx < tmp.size()){
            newAlphabet += tmp[idx];
            idx += aux.size();
        }
    }   
    //calcualte the resulting string
    for(string::iterator ch=text.begin(); ch!=text.end(); ++ch){
        if (*ch != ' ')
            result += alphabet[distance(newAlphabet.begin(), find(newAlphabet.begin(), newAlphabet.end(), *ch))];
        else
            result += ' ';
    }
    return result;
}



int main() {
    int n;
    string s;

    string keyword;
    //text to be deciphered
    string text;
    getline(cin, s);
    stringstream ss(s);
    ss >> n;
    for (int i=0; i<n; ++i){       
        getline(cin, keyword);
        getline(cin, text);
        cout << keywordTranspositionCipher(keyword, text) << endl;
    }
    return 0;
}

