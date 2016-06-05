/*
There are N buildings in a certain two-dimensional landscape. Each building has a height given by hi where i ε [1,N]. If you join K adjacent buildings, they will form a solid rectangle of area K*min(hi, hi+1, ... hi+k-1).

Given N buildings, find the greatest such solid area formed by consecutive buildings. 

Algorithm:
1. Add to stack if current value is equal or bigger than top of stack
2. Else, keep removing from stack till a stack-member which is smaller or equal than current is found
3. Calculate area every time you remove from stack:
	if (stack.empty())
		area = input[top] * i
	else
		area = input[top] * (i - stack.top() - 1)
*/
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int maxHistoArea(vector<int>& histogram){
    stack<int> histoIdx;	//store indices of histogram
	int i, top = 0, area = 0, maxArea = 0;
	
	for (i=0; i<histogram.size(); ){
		//if next column is greater push in stack
		if (histoIdx.empty() || histogram[i] >= histogram[histoIdx.top()]){
			histoIdx.push(i);
			top = i++;
		}
		else{
			top = histoIdx.top();
			histoIdx.pop();
			//if stack is empty calculate area from index top up to i
			if (histoIdx.empty())
				area = histogram[top] * i;
			//else area from i-1 to histoIdx.top()+1 has to form an area greater or equal to histogram[top]
			else
				area = histogram[top] * (i -  histoIdx.top() - 1);
			if (area > maxArea)
				maxArea = area;			
		}	
	}
	//process remaining elements in stack if we reach end of histogram
    while(!histoIdx.empty()){
		top = histoIdx.top();
		histoIdx.pop();
		if (histoIdx.empty())
			area = histogram[top] * i;
		else
			area = histogram[top] * (i -  histoIdx.top() - 1);
		if (area > maxArea)
			maxArea = area;
	}    
    return maxArea;
}


int main() {
    vector<int> histogram;
    int n;

    cin >> n;
    histogram.resize(n);
    for(unsigned i=0; i<n; ++i){
        cin >> histogram[i];
    }
    cout << maxHistoArea(histogram);
    return 0;
}