// Sort 0 and 1 in the array

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> arr = {0,1,0,1,1,0,0,1,0};
    int i=0;
    int j = arr.size()-1;
    while(i<j){
        if((arr[i]==1)&&arr[j]==0){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }else if(arr[i]==0){
            i++;
        }else if(arr[j]==1){
            j--;
        }
    }

    for(int k=0;k<arr.size();k++){
        cout << arr[k] << " ";
    }cout << endl;
    return 0;
}

