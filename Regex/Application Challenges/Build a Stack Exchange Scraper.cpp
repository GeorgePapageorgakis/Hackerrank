/*
We are interested in crawling and scraping as many questions as we can, from stack-exchange. 
http://electronics.stackexchange.com/questions is an example of a question library page from stack-exchange.

Scrape the questions from each library page, in the order in which they are listed. You will be provided with the markup of question listing pages, from which you need to detect:
(1) Identifier 
(2) Question text (which is on the Hyperlink to the question) 
(3) How long ago the question was asked.

The Markup in the Test Cases will be similar to the sample fragment shown below. Please note, that since this markup is real markup from the website, it is likely to contain some stray control and escape characters, unexpected whitespaces and newlines.

examples:
	<div class="question-summary" id="question-summary-80366">
	class="question-hyperlink">about power supply of opertional amplifier</a></h3>
	<span title="2013-08-27 18:07:58Z" class="relativetime">16 hours ago</span>
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <regex>
using namespace std;


/**
    Scrapes the questions from library pages, in the order in which they are listed. 
    Detects:
    (1) Identifier (2) Question text (Hyperlink to the question) (3) How long ago the question was asked.
	
    @param input markup text as a string
    @returns string vector with string format as (1);(2);(3)
*/
vector<string> websiteScrapper (const string text){
    vector<string> id, sub, time, ss;
    //set regex matching and pattern
    // NOTE: The regex constructor is explicit!
    vector<regex> vRegEx = { 
        regex("class\\s*?=\\s*?\"\\s*?question-summary\\s*?\"\\s*?id\\s*?=\\s*?\"(?:.|\\n)*?(\\d+)\\s*?\""),
        regex("class\\s*?=\\s*?\"\\s*?question-hyperlink\\s*?\"\\s*?>\\s*?(.*?)\\s*?\\<"),
        regex("class\\s*?=\\s*?\"\\s*?relativetime\\s*?\"\\s*?>\\s*?(.*?)\\s*?\\<") };
    string s;
    std::smatch m;

    for (unsigned i=0; i<vRegEx.size(); ++i){
        s = text;
        while (std::regex_search (s, m, vRegEx[i])) {
            if (i==0)
                id.push_back(m[1]);
            else if (i==1)
                sub.push_back(m[1]);
           else
                time.push_back(m[1]);
            s = m.suffix().str(); 
        }
    }
    //TODO: possible need for bound check...
    for(unsigned i=0; i<id.size(); ++i){
        ss.push_back(id.at(i) + ";" + sub.at(i) + ";" + time.at(i));
    }
    return ss;
}

int main() {
    string s, aux;
    //get markup text and store it as a string
    while(getline(cin, aux)){
        s += aux;
    }

    const vector<string>& ss = websiteScrapper(s);

    //print
    std::vector<string>::const_iterator i = ss.begin();
    while ( i != ss.end()) {
        std::cout << *i << endl;
        ++i;
    }
    return 0;
}