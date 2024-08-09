#include<iostream>
#include<vector>
using namespace std;

/*
Question Number: 34 on Leetcode
Find First and Last occurence of Element
We can use Binary Search to find it.

For First Occurence, We continue finding in left part to check that if target is present.
For Last Occurence, We continue finding in right part to check that if target is present.
*/


class Solution {
    int leftmost(vector<int>& nums, int target){
        // Initialise the boundary
        int left = 0;
        int right = nums.size()-1;
        // Initialise the variable to store the index of leftmost occurence of target
        int index = -1;
        while(left <= right){
            int mid = left + (right-left)/2;
            // We search in left part to check whether target appears in leftpart or not
            if(nums[mid] == target){
                // Store the mid
                index = mid;
                right = mid-1;
            }
            // If smaller then search in right part
            else if(nums[mid] < target){
                left = mid + 1;
            }
            // If bigger then search in left part
            else if(nums[mid] > target){
                right = mid - 1;
            }
        }
        return index;
    }
    int rightmost(vector<int>& nums, int target){
        // Initialise the boundary
        int left = 0;
        int right = nums.size()-1;
        // Initialise the variable to store the index of rightmost occurence of target
        int index = -1;
        while(left <= right){
            // We searcg in right part to check whether target appears in rightpart or not
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                // Store the mod
                index = mid;
                left = mid+1;
            }
            // If smaller then search in right part
            else if(nums[mid] < target){
                left = mid + 1;
            }
            // If bigger then search in left part
            else if(nums[mid] > target){
                right = mid - 1;
            }
        }
        return index;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = leftmost(nums, target);
        int right = rightmost(nums, target);
        vector<int> res;
        res.push_back(left);
        res.push_back(right);
        return res;
    }
};


int main(void){
    Solution S;
    vector<int> arr = {5,7,7,8,8,10};
    vector<int> answer = S.searchRange(arr, 8);
    cout << answer[0] << answer[1] << endl;
    return 0;
}