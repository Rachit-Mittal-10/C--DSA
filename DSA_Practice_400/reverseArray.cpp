#include "../Print.hpp"
#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int>& arr){
    int size = arr.size();
    int i = 0;
    while(i<=size/2){
        swap(arr[i],arr[size-i-1]);
        i++;
    }
}

int main(void){
    vector<int> arr = {4,1,2,9,3,81,8};
    Print(arr);
    reverseArray(arr);
    Print(arr);
    return 0;
}