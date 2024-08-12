/*
LeetCode Question: 347
Here we need to return K most frequest elements
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include"../Print.hpp"
using namespace std;

/*
Approach:
- Initialise the map.
- Initialise a priority queue.
- Initialise a answer array.
- Add the frequency of each unique elements to map.
- Add all entries of map to priority queue
- Run a loop from i = 0 to k:
    - Extract K elements
    - Add the first part of entries to answer array
*/

class Solution {
    // Custom Comparator
    class greaterValue{
    public:
        bool operator()(const pair<int,int>& i, const pair<int,int>& j){
            return i.second < j.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>> ,greaterValue> topKElements;
        for(auto i:mp){
            topKElements.push(i);
        }
        vector<int> answer;
        for(int i=0;i<k;i++){
            if(topKElements.empty()){
                break;
            }
            auto temp = topKElements.top();
            topKElements.pop();
            answer.push_back(temp.first);
        }
        return answer;
    }
};

int main(void){
    vector<int> arr = {1,1,1,3,2,2,4,5,5};
    int k = 3;
    vector<int> answer = Solution().topKFrequent(arr,k);
    Print(answer);
    return 0;
}