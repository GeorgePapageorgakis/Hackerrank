/*
Consider a database table, Emails, which has the attributes First Name and Email ID. Given N rows of data simulating the Emails table, print an alphabetically-ordered list of people whose email address ends in @gmail.com.

Constraints
    2≤N≤30
    Each of the first names consists of lower case letters [a−z] only.
    Each of the email IDs consists of lower case letters [a−z], @ and . only.
    The length of the first name is no longer than 20.
    The length of the email ID is no longer than 50.
*/
#include <set>
#include <regex>
#include <iostream>
using namespace std;

int main(){
    int N;
    multiset<string> ms;
    cin >> N;
    for(int a0 = 0; a0 < N; a0++){
        string firstName;
        string emailID;
        cin >> firstName >> emailID;
        if (std::regex_match (emailID, std::regex("^[a-z@.]{1,50}@gmail.com$") )){
            ms.insert(firstName);
        }
    }
    for(string i : ms)
        cout << i << endl;
    return 0;
}
