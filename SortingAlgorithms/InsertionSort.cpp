#include<iostream>
using namespace std;

// Using For Loop
void Insertion_Sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp = arr[i];
        int j=i-1;
        for(;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}

// Using While Loop
void Insertion_Sort_2(int arr[],int n){
    int i = 1;
    while(i<n){
        int temp = arr[i];
        int j = i - 1;
        while( (arr[j] > temp) && (j>=0) ){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
        i++;
    }
}

void Print_Array(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }cout << endl;
}

int main(){
    int arr[] = {1,4,5,0,9,8,7,6,2};
    Print_Array(arr,9);
    Insertion_Sort_2(arr,9);
    Print_Array(arr,9);
    return 0;
}