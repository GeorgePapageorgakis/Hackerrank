/*
Create a list of all the attributes of every tag found in HTML pages.

	<p>This is a paragraph</p>  

The above HTML string has p as its tag but no attributes.

	<a href="http://www.quackit.com/html/tutorial/html_links.cfm">Example Link</a>

This string has a as a tag and href as an attribute.

Input Format:
	The first line contains N, the number of lines in the HTML fragment. 
	This is followed by lines from a valid HTML document or fragment.

Constraints:
	Number of characters in the test fragments <= 10000 characters. 
	Characters will be restricted to ASCII. 
	Fragments for the tests will be picked up from Wikipedia.
	Attributes are all lowercase alphabets.
*/
#include <regex>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <iterator>
using namespace std;

/**
    @param input HTML code
    @return map<string, set<string>> sorted list of all the attributes of every tag found in HTML pages.
*/
std::map<string, set<string>> findHTMLAttributes(const vector<string>& text){
    std::map<string, set<string>> m;
    set<string> result;
    string s, aux;
    std::smatch mLine, mSub;
    
    for(unsigned i=0; i<text.size(); ++i){
        s = text[i];
        //get tags
        while (std::regex_search (s, mLine, regex("<(\\w+).*?>"))) {
            aux = static_cast<string>(mLine[0]);
            
            std::pair<std::map<string,set<string>>::iterator, bool> it =
                m.insert(std::make_pair((static_cast<string>(mLine[1])), set<string>()));
            result = it.first->second;

            //get attributes from captured mLine
            while (std::regex_search (aux, mSub, regex("\\s*?(\\w+)=\\s*?[\"\']"))) {
                result.insert(static_cast<string>(mSub[1]));
                aux = mSub.suffix().str();
            }
            it.first->second = result;
            s = mLine.suffix().str();
        }
    }
    return m;
}


int main() {
    vector<string> HTMLcode;
    string s, aux;
    int n;

    getline(std::cin, aux);
    stringstream numberline(aux);
    numberline >> n;
    for(int i=0; i<n; ++i){
        getline(cin, s);
        HTMLcode.push_back(s);
    }

    //find all HTML attributes
	const std::map<string, set<string>> mss = findHTMLAttributes(HTMLcode);
    
    //print HTML tag-attributes
    for(auto i : mss){
        cout << i.first << ":";
        set<string>::iterator j = i.second.begin(); 
        while(j!=i.second.end()){
            cout << *j;
            ++j;
            if (j!= i.second.end())
                cout << ",";
        }
        cout << endl;
    }

   
    return 0;
}