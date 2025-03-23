#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

class RecursiveSolution{
/*
: This explores all possible sequences and calculates the difference.
- Time Complexity: O(n choose m) ~ O(n^m)
! Exponential TC
-Space Complexity: O(n+m)
*/

    class CustomVector{
        vector<int> arr;
        int MAX,MIN;
        public:
            CustomVector(){
                arr = {};
                MAX = INT_MIN;
                MIN = INT_MAX;
            }

            void push_back(int x){
                arr.push_back(x);
                MAX = max(MAX,x);
                MIN = min(MIN,x);
            }

            void pop_back(){
                if(arr.size() <= 0){
                    return;
                }
                if(arr.size() == 1){
                    MAX = INT_MIN;
                    MIN = INT_MAX;
                    arr.pop_back();
                    return;
                }
                int x = arr.back();
                arr.pop_back();
                if(MAX == x){
                    MAX = *max_element(arr.begin(),arr.end());
                }
                if(MIN == x){
                    MIN = *min_element(arr.begin(), arr.end());
                }
            }

            int findDiff(){
                return (MAX-MIN);
            }

            int size(){
                return arr.size();
            }
    };

    void solve(vector<int>& arr, CustomVector& result, int m, int distributed, int index, int& MINDIFF){
        if(distributed >= m){
            int minDiff = result.findDiff();
            MINDIFF = min(MINDIFF, minDiff);
            return;
        }
        if(index >= arr.size()){
            return;
        }
        result.push_back(arr[index]);
        solve(arr,result,m,distributed+1,index+1,MINDIFF);
        result.pop_back();
        solve(arr,result,m,distributed,index+1,MINDIFF);
    }
public:
    int solve(vector<int>& arr, int m){
        auto result = CustomVector();
        int MINDIFF = INT_MAX;
        solve(arr,result, m, 0,0,MINDIFF);
        return MINDIFF;
    }
};

class SortWindowSolutionOptimised{
    /*
    todo: We first sort the array and then sliding window of m size
    */


public:
    int solve(vector<int>& arr, int m){
        sort(arr.begin(),arr.end());
        int MIN = INT_MAX;
        int n = arr.size();
        for(int i=0;i+m-1<n;i++){
            int diff = arr[i+m-1] - arr[i];
            MIN = min(diff,MIN);
        }
        return MIN;
    }
};

int main(void){
    vector<int> arr = {7, 6, 6, 5, 10, 12, 9, 11};
    auto Solution1 = RecursiveSolution();
    cout << Solution1.solve(arr,7) << endl;
    // cout << Solution1.solve(arr,5) << endl;
    auto Solution2 = SortWindowSolutionOptimised();
    cout << Solution2.solve(arr,7) << endl;
}