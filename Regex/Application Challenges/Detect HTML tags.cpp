/*
using regular expressions to detect the various tags used in an HTML document.

    Tags come in pairs. Some tag name, t, will have an opening tag, <t>, followed by some intermediate text, followed by a closing tag, </t>. The forward slash in a closing tag will always come before the tag name.
    The exception to this is self-closing tags, which consist of a single tag (not a pair) with a forward slash after the tag name: <p/>
*/

#include <regex>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    set<string> ss;
    string s, aux;
    int n;
    cin >> n;
    while(getline(cin, aux)){s += aux;}
    //set regex matching and pattern
    std::smatch m;
    std::regex reg ("<\\s*(\\w+)+");
	
    while (std::regex_search (s,m,reg)) {
        //m[0] contains <tag while m[1] contains tag
		ss.insert(m[1]);
        s = m.suffix().str();
    }
    
    //print
    std::set<string>::iterator i = ss.begin();
    while ( i != ss.end()) {
        std::cout << *i; 
        ++i;
        if (i != ss.end())
            cout << ";";
    }
    return 0;
}