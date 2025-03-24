/* 
todo: Leetcode Question 11
: Two Pointer Approach
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution{
public:
    int solve(vector<int>& arr){
        int start = 0;
        int end = arr.size()-1;
        int MAX_AREA = INT_MIN;
        while(start <= end){
            int area = min(arr[start],arr[end])*(end-start);
            MAX_AREA = max(MAX_AREA,area);
            if(arr[end] > arr[start]){
                start++;
            }
            else{
                end--;
            }
        }
        return MAX_AREA;
    }
};

int main(void){
    vector<int> arr = {1,8,6,2,5,4,8,3,7};
    auto S = Solution();
    cout << S.solve(arr) << endl;
}