/*
ou have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. You can change the height of a stack by removing and discarding its topmost cylinder any number of times.

Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. This means you must remove zero or more cylinders from the top of zero or more of the three stacks until they're all the same height, then print the height. The removals must be performed in such a way as to maximize the height.

Note: An empty stack is still a stack.
Sample Input
5 3 4
3 2 1 1 1
4 3 2
1 1 4 1

Sample Output
5
*/
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

int transformStackstoEqualHeight(vector<int>& h1, vector<int>& h2, vector<int>& h3, int s1, int s2, int s3){
    int i1=0,i2=0,i3=0;
    while(!(s1==s2 && s2==s3)){
        if (s1>=s2 && s1>=s3){
            s1 -= h1[i1];
            i1++;
        } 
        else if (s2>=s1 && s2>=s3){
            s2 -= h2[i2];
            i2++;
        } 
        else {
            s3 -= h3[i3];
            i3++;
        }
    }
    return s1;
}

int main(){
    int n1, n2, n3, s1 = 0, s2 = 0, s3 = 0;
    cin >> n1 >> n2 >> n3;
    
    vector<int> h1(n1);
    for(int h1_i = 0;h1_i < n1;h1_i++){
        cin >> h1[h1_i];
        s1 += h1[h1_i];
    }
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
       cin >> h2[h2_i];
        s2 += h2[h2_i];
    }
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
       cin >> h3[h3_i];
        s3 += h3[h3_i];
    }

    cout << transformStackstoEqualHeight(h1, h2, h3, s1, s2, s3) << endl;
    
    return 0;
}
