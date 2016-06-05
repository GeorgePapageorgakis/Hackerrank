/*
Maximum of all subarrays of size k
Time Complexity: O(n). We can observe that every element of array is added and removed at most once. So there are total 2n operations.
Auxiliary Space: O(k)
*/
#include <iostream>
#include <deque> 
using namespace std;
/*
Given a set of arrays of size N and an integer K, find the maximum integer for each and every contiguous subarray of size K for each of the given arrays.

Input Format
	First line of input will contain the number of test cases T. For each test case, you will be given the size of array N and the size of subarray to be used K. This will be followed by the elements of the array Ai.

Sample Input:
2
5 2
3 4 6 3 4
7 4
3 4 5 8 1 4 10

Sample Output:
4 6 6 4
8 8 8 10

Explanation:
For the first case, the contiguous subarrays of size 2 are {3,4},{4,6},{6,3} and {3,4}. The 4 maximum elements of subarray of size 2 are: 4 6 6 4. 
For the second case,the contiguous subarrays of size 4 are {3,4,5,8},{4,5,8,1},{5,8,1,4} and {8,1,4,10}. The 4 maximum element of subarray of size 4 are: 8 8 8 10.
*/

void printKMax(int arr[], int n, int k){
	// Create a Double Ended Queue, dq that will store INDEXES of array elements
    // The queue will store INDEXES of useful elements in every window and it will
    // maintain decreasing order of values from front to rear in dq, i.e., 
    // arr[dq.front[]] to arr[dq.rear()] are sorted in decreasing order
    std::deque<int>  dq(k);
    int i;
	
	/* Process first k (or first window) elements of array */
	for (i = 0; i < k; ++i){
        //For very element, previous smaller elements are useless so remove
        while ( (!dq.empty()) && arr[i] >= arr[dq.back()])
            dq.pop_back();
		//Add new element at rear of queue
        dq.push_back(i);
    }
    //Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for ( ; i<n; ++i){
		// The element at the front of the queue is the largest element of previous window
        printf("%d ", arr[dq.front()]);
        // Remove the elements which are out of this window
        while ( (!dq.empty()) && dq.front() <= i - k)
            dq.pop_front();
		
		//Remove all elements smaller than the currently
        //being added element (remove useless elements)
        while ( (!dq.empty()) && arr[i] >= arr[dq.back()])
            dq.pop_back();
		//Add current element at the rear of dq
        dq.push_back(i);
    }
	//Print the maximum element of last window
    printf("%d\n", arr[dq.front()]);
}


int main(){
    deque<int> mydeque;
    int t;
    scanf ("%d", &t);
    while(t>0) {
        int n,k;
        scanf ("%d %d",&n, &k);
        int i, j;
        int arr[n];
        for(i=0;i<n;i++){
            scanf ("%d", &j);
            arr[i] = j;
        }
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}