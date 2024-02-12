/**
 */


#include<bits/stdc++.h>
using namespace std;

// Bubble Sort
void Bubble_Sort(int arr[],int len){
    for(int i=0;i<len-1;i++){
        int flag = 0;
        for(int j=0;j<len-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag++;
            }
        }
        if(flag == 0){
            break;
        }
    }
}


void printArray(int arr[],int len){
    for(int i=0;i<len;i++){
        cout << arr[i] << " ";
    }cout << endl;
}


int main(){
    int arr[] = {1,4,2,3,7,0};
    cout << "Array before Sorting" << endl;
    printArray(arr,6);
    Bubble_Sort(arr,6);
    cout << "Array after Sorting" << endl;
    printArray(arr,6);
    return 0;
}