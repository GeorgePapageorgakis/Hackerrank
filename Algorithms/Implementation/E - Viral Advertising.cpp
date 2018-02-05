/*
HackerLand Enterprise is adopting a new viral advertising strategy. When they launch a new product, they advertise it to exactly 5 people on social media.

On the first day, half of those 5 people (i.e., floor(5/2) = 2 ) like the advertisement and each person shares it with of their friends; the remaining people (i.e., 5 - floor(5/2) = 3) delete the advertisement because it doesn't interest them. So, at the beginning of the second day, floor(5/2) * 3 = 2 * 3 = 6 people receive the advertisement.

On the second day, half of the 6 people who received the advertisement share it with new friends. So, at the beginning of the third day, floor(6/2) * 3 =  3 * 3 = 9 people receive the advertisement. The diagram below depicts the advertisement's virality over the first three days (green denotes a person that likes the advertisement and red denotes a person that disliked and deleted it):

https://s3.amazonaws.com/hr-challenge-images/26216/1475677928-3788004924-strangead.png

Assume that at the beginning of the ith day, m people received the advertisement, floor(m/2) people like and share it with 3 new friends, and m - floor(m/2) people dislike and delete it. At the beginning of the  (i + 1)th day, floor(m/2) * 3 people receive the advertisement.

Given an integer, n, find and print the total number of people who liked HackerLand Enterprise's advertisement during the first n days. It is guaranteed that no two people have any friends in common and, after a person shares the advertisement with a friend, the friend always sees it the next day.

1 <= n <= 50

Sample Input
3

Sample Output
9
*/

/*
Series Definition
n_{i+1} = floor{ 3/2 * n_{i} } and n_{0}=2.
*/

#include <iostream>
using namespace std;


int main() {
    int n, m, total;
    m = 2;
    total = 2;
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        m += (m>>1);
        total += m;
    }
    cout << total;
    return 0;
}