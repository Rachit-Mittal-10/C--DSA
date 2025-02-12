#include<iostream>
#include<vector>
#include<climits>
using namespace  std;

/*
Given the prices array whhere prices[i] is the price of given stock on ith day.

You want to maximise your profit by choosing a single day to buy the one stock and choosing different day to sell that stock.

Return the maximum profit.
*/
class Solution{
public:
    int getBestTimeSellBuy(vector<int>& prices){
        int n = prices.size();
        int lsf = INT_MAX;
        int profit = 0;
        int maxProfit = 0;
        for(int i=0;i<n;i++){
            lsf = min(lsf,prices[i]);
            profit = prices[i] - lsf;
            maxProfit = max(maxProfit,profit);
        }
        return maxProfit;
    }
};

int main(void){
    vector<int> prices = {7,1,5,3,6,4};
    cout << Solution().getBestTimeSellBuy(prices) << endl;
    return 0;
}