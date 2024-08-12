#include<iostream>
#include<vector>
using namespace std;

template <typename type>
void Print(vector<type>& arr){
    int size = arr.size();
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }cout << endl;
}

template <typename type>
void Print(vector<vector<type>> &arr){
    int row = arr.size();
    int col = arr[0].size();
    for(int i=0;i<row;i++){
        Print(arr[i]);
    }
}

void Print(int arr[], int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }cout << endl;
}



// void Print(int arr[][col], int row, int col){
//     for(int i=0;i<row;i++){

//     }
// }