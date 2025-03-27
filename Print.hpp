#include<iostream>
#include<vector>
#include<utility>
using namespace std;

template <typename type>
void Print(vector<type>& arr){
    for(auto& i:arr){
        cout << i << " ";
    }
    cout << endl;
}

template <typename type>
void Print(vector<vector<type>> &arr){
    for(auto& i:arr){
        Print(i);
    }
}

template <typename type1,typename type2>
void Print(vector<pair<type1,type2>>& arr){
    for(auto& i:arr){
        cout << "[" << i.first << ", " << i.second << "]"; 
    }
    cout << endl;
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