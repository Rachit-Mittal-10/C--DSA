#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class LinearSolution{
public:
    int getProfit(vector<int>& arr){
        int MAX_PROFIT = INT_MIN;
        int lsf = INT_MAX;
        int profit = 0;
        for(auto i:arr){
            lsf = min(i,lsf);
            profit = i - lsf;
            MAX_PROFIT = max(profit,MAX_PROFIT);
        }
        return MAX_PROFIT;
    }
};

int main(void){
    vector<int> arr = {1,5,2,7,10};
    auto Solution = LinearSolution();
    cout << Solution.getProfit(arr) << endl;
}