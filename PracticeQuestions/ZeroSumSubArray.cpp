// Zero Sum Sub Array

#include<bits/stdc++.h>
using namespace std;

// Function for finding Sub Arrays
vector<pair<int,int>> SubArray(int Arr[],int size){
    // Map to store Sum and Index
    unordered_map<int,vector<int>> Sum_Map;
    // Vector of Pair to store Indices
    vector<pair<int,int>> Vector_Index;

    int sum = 0;
    for(int i=0;i<size;i++){
        sum += Arr[i];
        if(sum==0){
            Vector_Index.push_back(make_pair(0,i));
        }
        // Element found
        if(Sum_Map.find(sum) != Sum_Map.end()){
            vector<int> vc = Sum_Map[sum];
            for(auto it = vc.begin();it!=vc.end();it++){
                Vector_Index.push_back(make_pair(*it+1,i));
            }
        }
        Sum_Map[sum].push_back(i);
    }
    return Vector_Index;
}

void Print(vector<pair<int,int>> Index,int Arr[]){
    for(auto it = Index.begin();it < Index.end();it++){
        cout << "Sub Array found from Index-" << it->first << " to Index-" << it->second << endl;
        for(int i = it->first ; i <= it->second ; i++){
            cout << Arr[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<pair<int,int>> Output = SubArray(arr,size);
    if(Output.size()!=0){
        Print(Output,arr);
    }else{
        cout << "No Such Arrays" << endl;
    }
    
    return 0;
}