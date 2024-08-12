/*
* LeetCode Question 128
todo Here you need to return the length of longest common subsequence in array.
*/

#include<vector>
#include<iostream>
#include"../Print.hpp"
using namespace std;

/*
* Approach
- @param nums: vector<int>
- Sort the Array
- Initialise a count array which will store the longest common subsequence till that point will all entries 1 and length equal to nums
- run a loop from i=1 to n:
    - diff = count[i] - count[i-1]
    - if diff = 0
        - count[i] = count[i-1]
    - if diff = 1:
        - count[i] = count[i-1]+1
- At the end find the maximum in count array and return it
*/

class Solution {
    /*
    * Time Complexity: O(nlogn)
    */
public:
    int longestConsecutive(vector<int>& nums) {
        if(n==0 || n==1){
            return n;
        }
        vector<int> temp = nums;
        int n = nums.size();
        sort(temp.begin(), temp.end());
        vector<int>count(n,1);
        for(int i=1;i<n;i++){
            if(temp[i]-temp[i-1] == 0){
                count[i] = count[i-1];
            }
            if(temp[i]-temp[i-1] == 1){
                count[i] = count[i-1]+1;
            }
        }
        int countMax = INT_MIN;
        for(int i=0;i<n;i++){
            countMax = max(countMax, count[i]);
        }
        return countMax;
    }
};

/*
* Approach2:
- Create set of array. This will ensure that We only had unique elements.
- Run a loop over set
    - Check if i-1 present in set or not, If not then find the length of subsequence

*/
class Solution2 {
// *Time Complexity: O(NlogN)
public:
    int longestConsecutive(vector<int>& nums) {
        set Set(nums.begin(),nums.end());
        int longest = 0;
        for(auto i:Set){
            if(Set.find(i-1) == Set.end()){
                // i is start
                int length = 0;
                // - Following Code is finding the length of subsequence
                while(Set.find(i+length) != Set.end()){
                    length++;
                }
                longest = max(longest,length);
            }
        }
        return longest;
    }
};