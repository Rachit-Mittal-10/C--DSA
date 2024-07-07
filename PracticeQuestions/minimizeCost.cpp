#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int minimizeCost(vector<int>& height, int n, int k) {
  vector<int> dp(n,-1);
  dp[0] = 0;
  for(int i=1;i<n;i++){
    vector<int> jumpMatrix(k+1,INT_MAX);
    for(int j=1;j<=k;j++){
      if(i-j>=0){
        jumpMatrix[j] = dp[i-j] + abs(height[j]-height[i-j]);
      }
    }
    dp[i] = *min_element(jumpMatrix.begin(),jumpMatrix.end());
  }
  return dp[n-1];
}
int main() {
  vector<int> height = {10,30,40,50,20};
  cout << minimizeCost(height,5,3) << endl;
  return 0;
}