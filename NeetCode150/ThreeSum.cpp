/*
* ThreeSum
* Leetcode 15

todo Find index i,j,k such that nums[i] + nums[j] + nums[k] == 0
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include"../Print.hpp"
using namespace std;

/*
* Approach-1
- Run a loop nested to three level to parse the vector.
- Inside the innermost loop, check for condition that element sum to 0.
- If they do then make temperory vector, store the result. sort the array. If temp array already present in answer then skip otherwise add to answer array
- We sort the array to remove duplicates. order does not matter so -1,-1,2 and -1,2,-1 are same.
*/
class Solution1{
    int countElement(vector<vector<int>> input, vector<int> element){
        int count=0;
        for(auto i:input){
            if(i==element){
                count++;
            }
        }
        return count;
    }
public:
    vector<vector<int>> threesum(vector<int> arr){
        int n = arr.size();
        vector<vector<int>> answer;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[i]+arr[j]+arr[k]==0){
                        vector<int> temp = {arr[i],arr[j],arr[k]};
                        sort(temp.begin(),temp.end());
                        if(countElement(answer,temp) ==0){
                            answer.push_back(temp);
                        }
                    }
                }
            }
        }
        return answer;
    }
};
/*
* Approach-2
! One thing to notice is that for summing over to zero, We always will need atleast one negative element and atleast one positive element except when there are three 0 in input-array
- We try to reduce the problem to two sum 2 problem. How? num[i]+num[j]+num[k] = 0 => nums[i] = - (nums[j]+nums[k]).
- Now finding RHS is an two sum problem over sorted array.
*Algo:
- Sort the Array
- Find the size of Array
- Initialise the result
- if 0th element positive then return result
- if last element negative then return result
- run a loop from i=0 to n-2:
    - To skip over duplicate we skip if prev and curr element aare same
    - othersum = - nums[i]
    - Apply TwoSum2 over array starting from i+1 to n-1
*/
class Solution2{

public:
    vector<vector<int>> threesum(vector<int> arr){
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> result;
        //* If 0th position had positive element then it mean absence of negative element hence no result
        if(arr[0]>0){
            return result;
        }
        //* If last position had negative element then it mean absence of negative elemnet hence no result
        if(arr[n-1]<0){
            return result;
        }
        int target, start, end, sum;
        for(int i=0;i<n-2;i++){
            if(i && arr[i] == arr[i-1]){
                continue;
            }
            if(arr[i]>0){
                return result;
            }
            target = -arr[i];
            start = i+1;
            end = n-1;
            while(start<end){
                sum = arr[start]+arr[end];
                if(sum == target){
                    vector<int> temp = {arr[i],arr[start],arr[end]};
                    result.push_back(temp);
                    start++;
                    end--;
                }
                else if(sum>target){
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        return result;
    }
};


int main(void){
    vector<int> nums = {-1,0,1,2,-1,-2};
    vector<vector<int>> answer = Solution1().threesum(nums);
    vector<vector<int>> answer2 = Solution2().threesum(nums);
    cout << "Solution1" << endl;
    Print(answer);
    cout << "Solution2" << endl;
    Print(answer2);
    return 0;
}