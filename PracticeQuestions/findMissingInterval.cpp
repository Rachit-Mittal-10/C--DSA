/* 
: TCS NQT Question

You are given the lower limit, l and upperlimit, u and sorted integer array of size n. Returns the pairs such that element does not occurs in integer array.
Example: 
l = 1
u = 10
n = 1
arr: 5

Output: [1,4][6,10]

*/

#include<iostream>
#include<vector>
#include<utility>
using namespace std;

class NLogNApproach{
    bool checkArr(vector<int>& arr, int target){
        int start = 0;
        int end = arr.size()-1;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid] == target){
                return true;
            }
            else if(arr[mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return false;
    }
public:
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
    vector<pair<int,int>> solve(vector<int>& arr, int l, int u){
        vector<bool> hashArray(u-l+1,false);
        // loop l-u times ===> n
        for(int i=l;i<=u;i++){
            // log n for checkArr
            hashArray[i-l] = checkArr(arr,i);
        }
        vector<pair<int,int>> result;
        int start = -1;
        // l -u times ===> n times
        for(int i=0;i<hashArray.size();i++){
            if(!hashArray[i]){
                if(start == -1){
                    start = l+i;
                }
            }
            else{
                if(start != -1){
                    result.push_back(make_pair(start,l+i-1));
                    start = -1;
                }
            }
        }
        if(start != -1){
            result.push_back(make_pair(start,u));
        }
        return result;
    }
};

int main(void){
    vector<int> arr = {5,10,17,34,48,67,89};
    auto S = NLogNApproach();
    auto result = S.solve(arr,1,100);
    for(auto& p: result){
        cout << "[" << p.first << "," << p.second << "]";
    }
    cout << endl;
}