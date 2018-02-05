/*
HackerLand University has the following grading policy:

    - Every student receives a grade in the inclusive range from 0 to 100.
    - Any grade less than 40 is a failing grade.

Sam is a professor at the university and likes to round each student's grade according to these rules:

    - If the difference between the grade and the next multiple of 5 is less than 3, round grade up to the next multiple of 5.
    - If the value of grade is less than 38, no rounding occurs as the result will still be a failing grade.

Sample Input 0
4
73
67
38
33

Sample Output 0
75
67
40
33
*/

#include <bits/stdc++.h>

using namespace std;

vector < int > solve(vector < int > grades){
    for (ssize_t i = 0; i < grades.size(); ++i) {
        int margin = 0;
        if ( grades[i] > 40){
            margin  = grades[i] % 5;
            if ((margin < 5) && (margin > 2))
                grades[i] = ((grades[i]/5) * 5)+ 5;        
        }
        else if(grades[i] > 37){
            grades[i] = 40;
        }
    }
    return grades;
}

int main() {
    int n;
    cin >> n;
    vector<int> grades(n);
    for(int grades_i = 0; grades_i < n; grades_i++){
       cin >> grades[grades_i];
    }
    vector < int > result = solve(grades);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;
    
    return 0;
}
