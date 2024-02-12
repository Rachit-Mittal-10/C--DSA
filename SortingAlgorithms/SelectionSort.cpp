#include<bits/stdc++.h>
using namespace std;


// Selection Sort Algorithm
void Selection_Sort(int arr[],int len){
    int minIndex;
    for(int i=0;i<len-1;i++){
        minIndex = i;
        for(int j = i+1 ; j<len ;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
    
}

void printArray(int arr[],int len){
    for(int i=0;i<len;i++){
        cout << arr[i] << " ";
    }cout << endl;
}

int main(){
    int arr[] = {4,3,5,8,1};
    printArray(arr,5);
    Selection_Sort(arr,5);
    printArray(arr,5);
    return 0;
}