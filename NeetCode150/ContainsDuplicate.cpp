/*
LeetCode Question: 217
Here We need to tell whether there's exist an element which occurs twice or not
*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
/*
Approach
- Initialise the map which stores whether the element has been visited or not
- For i=0 to n:
    - If key exist in map then return true
    - Otherwise update the key status as true
- return false if it there's no duplicate
*/
bool containsDuplicate(vector<int>& nums) {
    unordered_map<int,bool> mp;
    int len = nums.size();
    for(int i=0;i<len;i++){
        if(mp.find(nums[i]) != mp.end()){
            return true;
        }
        mp[nums[i]] = true;
    }
    return false;
}


int main(void){
    vector<int> arr = {1,3,2,4};
    cout << boolalpha <<  containsDuplicate(arr) << endl;
}