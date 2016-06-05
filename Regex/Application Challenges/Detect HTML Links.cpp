/*
strip the links and the text name from the html pages.
A html link is of the form,

	<a href="http://www.hackerrank.com">HackerRank</a>  

Where a is the tag and href is an attribute which holds the link charlie is interested in. The text name is HackerRank. Text name can sometimes be hidden within multiple tags

	<a href="http://www.hackerrank.com"><h1><b>HackerRank</b></h1></a>

Here, the text name is hidden inside the tags h1 and b. 
Output Format:
	link-1,text name-1
	link-2,text name-2
*/
#include <regex>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
using namespace std;

/*
Take text input in vector container
return a vector of strings with HTML links and text names
*/
vector<string> find_HTML_names(const vector<string>& text){
    vector<string> vs;
    string s;
    //set regex matching and pattern
    std::smatch m;
	//<a.*?href="(.*?)".*?>(.*?)<\/a>
    regex reg("<a.*?href=\\\"(.+?)\\\".*?>(?:<.*?>)?(?:\\s*)?(.*?)(?:<.*?>)?<\\/a");
    //check each text line for HTML pattern
    for(int i=0; i<text.size(); ++i){
        s = text[i];
        while (std::regex_search (s,m,reg)) {
            string aux = m[1];
            aux += ",";
            aux += m[2];
            vs.push_back(aux);
           /* for (auto i : m)
                cout << i << "   ";
            cout << endl;*/
            s = m.suffix().str();
        }
    }
    return vs;
}

int main() {
    vector<string> N_str;
    //set<string> ss;
    string s, aux;
    int n;

    //get N strings
    getline(std::cin, aux);
    stringstream numberline(aux);
    numberline >> n;
    for(int i=0; i<n; ++i){
        //get string
        getline(cin, s);
        N_str.push_back(s);
    }

    //find all email addresses
	const vector<string>& ss = find_HTML_names(N_str);

    //print
    std::vector<string>::const_iterator i = ss.begin();
    while ( i != ss.end()) {
        std::cout << *i << endl; 
        ++i;
    }
    return 0;
}