/*
* LeetCode 238
TODO Here you need to return array where each element is Product of Array except itself

* Example:
- Input: 1,2,3,4
- Output: 24,12,8,6
* Reasoning:
- 24 = 2*3*4
- 12 = 1*3*4
- 8 = 1*2*4
- 6 = 1*2*3
*/

#include<iostream>
#include<vector>
#include"../Print.hpp"
using namespace std;


/*
* Approach:
  @param nums
- Get the length of nums input array
- Initialise output array
- Initilaise prefix and suffix array where prefix will store product of number till ith index and 
- suffix array will store product of number from i to end
- prefix[0] = nums[0]
- suffix[n-1] = nums[n-1]
- Run a loop from i=1 to n:
    - prefix[i] = prefix[i-1]*nums[i]
- Run a loop from i=n-2 to 0(inclusive):
    - suffix[i] = suffix[i+1]*nums[i]
- Run a loop from i=0 to n:
    - if i==0:
        - output[i] = 1*suffix[i+1]
    - else if i==n-1:
        - output[i] = prefix[i-1]*1
    - else:
        - output[i] = prefix[i-1]*suffix[i+1]
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n,-1);
        vector<int> prefix(n,-1);
        vector<int> suffix(n,-1);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]*nums[i];
        }
        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1]*nums[i];
        }
        for(int i=0;i<n;i++){
            if(i==0){
                output[i] = suffix[i+1];
            }
            else if(i==n-1){
                output[i] = prefix[i-1];
            }
            else{
                output[i] = prefix[i-1]*suffix[i+1];
            }
        }
        return output;
    }
};

int main(void){
    vector<int> nums = {1,2,3,4};
    vector<int> answer = Solution().productExceptSelf(nums);
    Print(nums);
    Print(answer);
    return 0;
}