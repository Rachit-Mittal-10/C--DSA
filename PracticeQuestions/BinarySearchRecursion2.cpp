#include<bits/stdc++.h>
using namespace std;

int binarysearch(int* input,int n,int val);
int binarysearch(int* input,int StartIndex, int EndIndex, int val);

int main(){
    int test[] = {6,11,22,23,43,46,52,54,67,80,100};
    int size = sizeof(test)/sizeof(test[0]);
    cout << getbinarysearch(test,size,80);
    return 0;
}

int binarysearch(int* input,int n,int val){
    int StartIndex = 0;
    int EndIndex = n - 1;

    return binarysearch(input,StartIndex,EndIndex,val);
}

int binarysearch(int* input,int StartIndex,int EndIndex,int val){
    int midIndex = StartIndex + (EndIndex - StartIndex);
    
    if(StartIndex > EndIndex){
        return -1;
    }

    int ans = -1;
    if(input[midIndex] == val){
        ans = midIndex;
    }
    else if(input[midIndex] > val){
        ans = binarysearch(input,StartIndex,midIndex-1,val);
    }
    else{
        ans = binarysearch(input,midIndex+1,EndIndex,val);
    }
    return ans;
}