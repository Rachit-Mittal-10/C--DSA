#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
    int maxAreaBruteForce(vector<int>& arr){
        int n = arr.size();
        int maxArea = INT_MIN;
        int width, height, area;
        // Brute Force Approach
        // TC: O(N^2)
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int width = j-i;
                int height = min(arr[i],arr[j]);
                area = width * height;
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
    int maxArea2Pointer(vector<int>& arr){
        int left = 0;
        int right = arr.size()-1;
        int maxArea = INT_MIN;
        while(left<=right){
            int width = right - left;
            int height = min(arr[right], arr[left]);
            int area = width * height;
            maxArea = max(maxArea, area);
            //* Here we make decision to update the left and right pointer
            //* We keep the index having larger value of height
            //* Since larger height is more likely to reach maxArea possible
            if(arr[right] > arr[left]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
public:
    int maxArea(vector<int>& height) {
        return maxArea2Pointer(height);
    }
};


int main(void){
    vector<int> arr = {1,8,6,2,5,4,8,3,7};
    cout << Solution().maxArea(arr) << endl;
    return 0;
}