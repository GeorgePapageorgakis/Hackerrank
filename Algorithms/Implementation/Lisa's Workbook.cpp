#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*A workbook contains exercise problems, grouped into chapters.

    - There are nn chapters in Lisa's workbook, numbered from 1 to n.
    - The ii-th chapter has titi problems, numbered from 1 to ti.
    - Each page can hold up to k problems. There are no empty pages or unnecessary spaces, so only the - last page of a chapter may contain fewer than k problems.
    - Each new chapter starts on a new page, so a page will never contain problems from more than one
	  chapter.
    - The page number indexing starts at 1.

Lisa believes a problem to be special if its index (within a chapter) is the same as the page number where it's located. Given the details for Lisa's workbook, can you count its number of special problems?

Sample Input:
5 3  
4 2 6 1 10

Sample Output:
4
*/

int main() {
    int n , k, count=0, index = 1;
    cin >> n >> k;
    //input to vector
    vector<int> chapters( std::istream_iterator<int>( std::cin ), std::istream_iterator<int>() );

    for (int probIdx : chapters){
        int low_bound = 0, up_bound = 0;
        //create reference values for pages-problems index eg. 3 4 2 3 6 1 3 6 9 10
        do{     
            up_bound = (up_bound + k < probIdx ? up_bound + k : probIdx);
            low_bound = (up_bound%k == 0 ? up_bound - k : up_bound - up_bound%k);
            if ((index > low_bound) && (index < up_bound+1))
                ++count;
            ++index;
        }while (up_bound < probIdx);
    }
    cout << count << endl;
    
    return 0;
}