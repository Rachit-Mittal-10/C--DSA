/*
* LeetCode Question 875: Koko Eating Bananas

@params piles: vector of int
@params h: int

todo: find the minimum eating Speed such that koko eats all bananas in less than `h` hours
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int getHours(vector<int>piles, int k){
        int hour = 0;
        int n = piles.size();
        int i=0;
        while(i<n){
            if(piles[i] <= 0){
                i++;
                continue;
            }
            piles[i] = piles[i]-k;
            hour = hour+1;
        }
        return hour;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high = 0;
        for(int i=0;i<n;i++){
            high = max(high,piles[i]);
        }
        int result=high;
        while(low<=high){
            int mid = low + (high-low)/2;
            int hour = getHours(piles,mid);
            if(hour <= h){
                result = min(result,mid);
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
    }
};

int main(void){
    vector<int> piles = {3,6,7,11};
    int h=8;
    cout << Solution().minEatingSpeed(piles,h) << endl;
}