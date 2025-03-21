#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

/*
Using a vector to store number which has traversed yet
*/
bool containsDuplicateVec(vector<int>& arr){
    if(arr.size() == 0 || arr.size() == 1){
        return false;
    }
    vector<int> vec;
    for(auto i:arr){
        if(find(vec.begin(),vec.end(),i) != vec.end()){
            return true;
        }
        vec.push_back(i);
    }
    return false;
}

int main(void){
    vector<int> arr1 = {};
    vector<int> arr2 = {1};
    cout << boolalpha << containsDuplicateVec(arr2) << endl;
    return 0;
}