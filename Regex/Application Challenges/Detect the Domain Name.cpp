/*
provided with a chunk of HTML markup. Your task is to identify the unique domain names from the links or Urls which are present in the markup fragment.

For example, if the link http://www.hackerrank.com/contest is present in the markup, you should detect the domain: hackerrank.com. In case there are second level or higher level domains present in the markup, all of them need to be treated as unique. For instance if the links http://www.xyz.com/news, https://abc.xyz.com/jobs, http://abcd.xyz.com/jobs2 are present in the markup then [xyz.com, abc.xyz.com, abcd.xyz.com] should all be identified as unique domains present in the markup. Prefixes like "www." and "ww2.", if present, should be scrubbed out from the domain name. 
*/
#include <regex>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <iterator>
using namespace std;

/**
    @param input vector text
    @return set with all domain names
*/
set<string> find_domain_names(const vector<string>& text){
    set<string> ss;
    string s;
    //set regex matching and pattern
    std::smatch m;    
    regex reg("(?:(?:https?://(?:ww[w2]\\.)?)((?:[\\w-]+\\.)+(?:[a-z]{2,3})))");
        
    //check each text line for email pattern
    for(int i=0; i<text.size(); ++i){
        s = text[i];
        while (std::regex_search (s,m,reg)) {
            ss.insert(m[1]);
            /*
            for (auto i : m)
                cout << i << "   ";
            cout << endl;
            */
            s = m.suffix().str();
        }
    }
    return ss;
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
	const set<string>& ss = find_domain_names(N_str);

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
