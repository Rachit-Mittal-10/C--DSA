/*
* LeetCode Question: 167
* Two Sum 2
* Array is sortyed in non increasing order
*/

#include<vector>
#include<iostream>
#include"../Print.hpp"
using namespace std;

/*
* Approach
- Apply Binary search with one change.
- Instead of running according to mid, calculate the sum of element at start and end.
- Compare the sum to target sum and run Binary Search accordingly
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer = {-1,-1};
        int start = 0;
        int end = numbers.size()-1;
        while(start<=end){
            int sum = numbers[start] + numbers[end];
            //* If equal then set the answer
            if(sum == target){
                answer[0] = start+1;
                answer[1] = end+1;
                break;
            }
            //* If sum greater then move behind from end. Since We need to decrease the sum, We should remove the larger element.
            else if(sum > target){
                end--;
            }
            //* If sum more then move forward from start. Since we need to increase the sum, We should remove less number.
            else if(sum < target){
                start++;
            }
        }
        return answer;
    }
};

int main(void){
    vector<int> numbers = {2,7,11,12};
    int target = 9;
    vector<int> answer = Solution().twoSum(numbers, target);
    Print(answer);
    return 0;
}