#include<iostream>
#include<climits>
#include<vector>
using namespace std;

pair<int,int> getMaxMin(vector<int> temp){
    int Min = INT_MAX;
    int Max = INT_MIN;
    for(auto i:temp){
        Min = min(Min,i);
        Max = max(Max,i);
    }
    return make_pair(Min,Max);
}

int main(void){
    vector<int> temp = {10,2,1,5,9,8,6};
    auto ans = getMaxMin(temp);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}