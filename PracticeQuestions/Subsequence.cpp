/*
Subsequence means the sequence(contiguous/non-contiguous) of element that follow the order
*/
#include<iostream>
#include<vector>
#include "../Print.hpp"
using namespace std;

/*
Approach: Pick-Not Pick
Make an empty Array to store the subsequence(passed as parameter)
*/

void getSubsequence(vector<int> inputArray);
void getSubsequenceUtil(vector<int> array, vector<int> inputArray, int index, int n);

int main(void){
    vector<int> inputArray = {3,1,2};
    getSubsequence(inputArray);
}

void getSubsequence(vector<int> inputArray){
    vector<int> emptyArray;
    int n = inputArray.size();
    getSubsequenceUtil(emptyArray,inputArray,0,n);
    return;
}

void getSubsequenceUtil(vector<int> array,vector<int> inputArray, int index, int n){
    if(index >= n){
        Print(array);
        return;
    }
    array.push_back(inputArray[index]);
    getSubsequenceUtil(array,inputArray,index+1,n);
    array.pop_back();
    getSubsequenceUtil(array,inputArray,index+1,n);
    return;
}