/*
A gene is represented as a string of length (where is divisible by 4), composed of the letters A, C, T, and G. It is considered to be steady if each of the four letters occurs exactly n/4 times. For example, GACT and AAGTGCCT are both steady genes.

Bear Limak is a famous biotechnology scientist who specializes in modifying bear DNA to make it steady. Right now, he is examining a gene represented as a string s. It is not necessarily steady. Fortunately, Limak can choose one (maybe empty) substring s of and replace it with any substring of the same length.

Modifying a large substring of bear genes can be dangerous. Given a string s, can you help Limak find the length of the smallest possible substring that he can replace to make s a steady gene?

Note: A substring of a string S is a subsequence made up of zero or more consecutive characters of S.

Sample Input:
8  
GAAATAAA

Sample Output
5

40
TGATGCCGTCCCCTCAACTTGAGTGCTCCTAATGCGTTGC

TGAT GCCG TCCC CTCA ACTT GAGT GCTC CTAA TGCG TTGC
*/
#include <climits>
#include <map>
#include <iostream>
#include <string>
using namespace std;

bool steadyLimCheck(map<char, int>& freqGene, int& limit){
    if(freqGene['A'] <= limit && freqGene['C'] <= limit && freqGene['G'] <= limit && freqGene['T'] <= limit)
        return true;
    else
       return false;
}

/**
    @param input gene string
    @return the length of the smallest possible substring that he can replace to make s a steady gene
    a gene is steady if each of the four letters occurs exactly n/4 times.
*/
int minStrSteadyGene(std::string& s, int& N){
    map<char, int> freqGene;
    int maxIndex = 0, minLen = INT_MAX, limit = N / 4;;
    //start from right side
    for (int i = N; i > 0; --i){
        ++freqGene[s[i- 1]];
        if(!steadyLimCheck(freqGene, limit)){
            maxIndex = i;
            --freqGene[s[i - 1]];
            break;
        }
    }
	//start from left side and trim range in each itteration subjected to n/4 criterion
    for(int minIndex = -1; minIndex < N - 1 && maxIndex < N && minIndex < maxIndex; ++minIndex){
		//find new maxindex by removing chars from substring until freq of all letters < n/4
        while(!steadyLimCheck(freqGene, limit) && maxIndex < N){
            --freqGene[s[maxIndex]];
            ++maxIndex;
        }
        if(maxIndex > N || !steadyLimCheck(freqGene, limit))
            break;
		//calculate substring length, and min length
        int subStrLen = max(0, maxIndex - minIndex - 1);
        if(subStrLen < minLen)
            minLen = subStrLen;
		//add freq char from left
        ++freqGene[s[minIndex + 1]];
    }
    return minLen;
}

int main() {
    //n is always divisible by 4
    int n;
    string gene;
    cin >> n;
    cin >> gene;
    
    std::cout << minStrSteadyGene(gene, n) << endl;

    return 0;
}
