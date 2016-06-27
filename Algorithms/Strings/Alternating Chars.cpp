/*
Shashank likes strings in which consecutive characters are different. For example, he likes ABABA, while he doesn't like ABAA. Given a string containing characters A and B only, he wants to change it into a string he likes. To do this, he is allowed to delete the characters in the string.

Your task is to find the minimum number of required deletions.
Sample Input
5
AAAA
BBBBB
ABABABAB
BABABA
AAABBB

Sample Output
3
4
0
0
4
*/
#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

int minNumDeletions(string& s){
    int c=0;
    char ch = *s.begin();
    for(std::string::iterator it = s.begin()+1; it!=s.end(); ++it ){
        if (*it == ch)
            ++c;
        ch = *it;
    }
    return c;
}

int main() {   
    string s;
    vector<string> vs;
    cin.ignore(8,'\n');
    //vector<string> vs( std::istream_iterator<string>( std::cin ), std::istream_iterator<string>() );

    while (getline(cin, s)){
        vs.push_back(s);
    }
    
    for (string i : vs)
        cout << minNumDeletions(i) << endl;        

    return 0;
}