/*
Given a line of text which possibly contains the latitude and longitude of a point, can you use regular expressions to identify the latitude and longitude referred to (if any)?

Constraints:
1 <= N <= 100
The latitude and longitude, (X, Y) where X and Y are decimal numbers (latitude, longitude) pair:
	-90<=X<=+90 and -180<=Y<=180.
They will not contain any symbols for degrees or radians or N/S/E/W. There may or may not be a +/- sign preceding X or Y.
There will be a space between Y and the comma before it.
There will be no space between X and the preceding left-bracket, or between Y and the following right-bracket.
There will be no unnecessary zeros (0) before X or Y.


Sample Input
6
(75, 180)
(+90.0, -147.45)
(+90, +180)
(-90.00000, -180.0000)
(90., 180.)
(-090.00000, -180.0000)
*/
#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <regex>
using namespace std;


/**
    @param input string with lantitude-longtitude
    @return true if format is correct, false otherwise
*/
bool isValidGeoCoord(string& s){

    if (std::regex_match (s,
        std::regex("^\\([\\+\\-]?((90(\\.0+)?)|([1-8]?\\d(\\.\\d+)?)),\\s*?[\\+\\-]?((180(\\.0+)?)|(1[0-7]\\d(\\.\\d+)?)|([1-9]?\\d(\\.\\d+)?))\\)$")))
        return true; 
    return false;
}

int main() {
    vector<string> N_str;
    string s;
    int n;

    //get N strings
    getline(std::cin, s);
    stringstream numberline(s);
    numberline >> n;
    for(int i=0; i<n; ++i){
        //get string
        getline(cin, s);
        N_str.push_back(s);
    }

    //find all valid Geographical Coordinates
    for(int i=0; i<n; ++i){
        if (isValidGeoCoord(N_str[i]))
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}
