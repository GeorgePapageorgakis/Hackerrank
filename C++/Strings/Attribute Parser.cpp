/*
In our defined markup language HRML, each element consists of a starting and ending tag, and there are attributes associated with each tag. Only starting tags can have attributes. We can call an attribute by referencing the tag, followed by a tilde, '~' and the name of the attribute. The tags may also be nested.

The opening tags follow the format:

	<tag-name attribute1-name = "value1" attribute2-name = "value2" ... >

The closing tags follow the format:

	< /tag-name >

For example:
	<tag1 value = "HelloWorld">
	<tag2 name = "Name1">
	</tag2>
	</tag1>

The attributes are referenced as:
	tag1~value  
	tag1.tag2~name
	
Given the source code in HRML format consisting of N lines answer Q queries. Each query asks you to print the value of the attribute specified. Print "Not Found!" if there isn't any such attribute.
*/
#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <iterator>
using namespace std;


/**
	@param input markup HRML code text as a string
    @returns all available variables that were detected in the code, mapped

**/
map<string, string> parseVariableNames(const string& textcode ){
    map<string, string> mss;
    string s, tag, attr, val;
    int nest_lvl=0;
    
    istringstream iss(textcode);
    
    while(iss >> s) {
        if(s[0] == '<'){
            if(s[1] == '/'){
                --nest_lvl;
                if (nest_lvl == 0)
                    tag = "";
                else if(!tag.empty())
                    tag.erase (tag.begin() + tag.find_last_of("."), tag.end());
            }
            else{
                if (nest_lvl != 0){
                    tag += ".";
                    tag +=  s.substr(1, s.size()-1);
                }
                else
                    tag = s.substr(1, s.size() - (s[s.size()-1] == '>' ? 2 : 1) );
                ++nest_lvl;
            }
        }
        else if(s[0] == '"'){
            val = s.substr(1, s.size() - (s[s.size()-1] == '>' ? 3 : 2) );
			mss.insert(make_pair(tag+attr, val));
        }
        else if(s[0] != '='){
            attr = "~" + s;
        }
    }
    return mss;
}


int main() {
    int N, Q;
    string HRMLtextcode, s;
    
    getline (cin, s);
    stringstream numberline(s);
    numberline >> N >> Q;
    //get HRML code and store as a string
    for (unsigned line=0; line<N; ++line){
        getline (cin, s);
        stringstream numberline(s);
        s += "\n";
        HRMLtextcode += s;
    }

    const map<string, string>& results = parseVariableNames(HRMLtextcode);

    for (int i = 0; i < Q; i++) {
        getline (cin, s);
        stringstream numberline(s);
        map<string, string>::const_iterator it = results.find(s);
        if (it != results.end()) {
            cout << it -> second << endl;
        }
        else cout << "Not Found!" << endl;
    }   
    return 0;
}
