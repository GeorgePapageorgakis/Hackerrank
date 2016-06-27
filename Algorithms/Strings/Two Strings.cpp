/*
You are given two strings, A and B. Find if there is a substring that appears in both A and B.
Sample Input
2
hello
world
hi
world

Sample Output
YES
NO
*/
#include <string>
#include <iostream>

std::string findCommonStr(std::string& s1, std::string& s2){
    for(char c : "abcdefghijklmnopqrstuvwxyz"){
        if ((s1.find(c) != std::string::npos) && (s2.find(c) != std::string::npos))
            return "YES";
    }
    return "NO";
}

int main() {
    int n;
    std::string s1, s2;
    std::cin >> n;
    for(int i=0; i<n; ++i){
        std::cin >> s1;
        std::cin >> s2;
        std::cout << findCommonStr(s1, s2) << std::endl;        
    }
    return 0;
}