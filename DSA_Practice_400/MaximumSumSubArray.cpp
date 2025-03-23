// LeetCode 53
// Different from MaximumSumSubArray of size K

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


class IterativeBruteForceApproach{
public:
    /*
    : Looping through each sub array and finding out the maximum
    - TC: O(N^2)
    - SC: O(1)
    */
    int MaximumSumSubArray1(vector<int>& arr){
        int result = INT_MIN;
        int n = arr.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = 0;
            for(int j=i;j<n;j++){
                sum += arr[j];
                result = max(result,sum);
            }
        }
        return result;
    }
};

class RecursiveApproach{
    /*
    : Recursive Approach: At index i consider that element has two possibilities: Pick or Not Pick.
    : Pick expands the array and Not Pick ends the array and calculates the sum
    */
    int maxSoFar = INT_MIN;
};

int main(void){
    vector<int> arr = {-2,-3,4,-1,-2,1,5,-3};
    auto Solution1 = IterativeBruteForceApproach();
    auto Solution2 = RecursiveApproach();
    cout << Solution1.MaximumSumSubArray1(arr) << endl;
    cout << Solution2 .MaximumSumSubArray(arr) << endl;
    return 0;
}