#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

class BruteForceApproach{
public:
    vector<pair<int,int>> solve(vector<pair<int,int>>& ip){
        //  nlogn
        sort(ip.begin(),ip.end()); 
        vector<pair<int,int>> result;
        int n = ip.size();
        // n since every element visted exactly once
        for(int i=0;i<n;i++){
            pair<int,int>& p = ip[i];
            if(!result.empty() && p.second <= result.back().second){
                continue;
            }
            for(int j=i+1;j<n;j++ ){
                pair<int,int>& q = ip[j];
                if(q.first <= p.second){
                    p.second = max(p.second, q.second);
                }
                else{
                    break;
                }
            }
            result.push_back(p);
        }
        return result;
    }
};

class OptimisedSolution{
public:
    vector<pair<int,int>> solve(vector<pair<int,int>>& ip){
        //  nlogn
        sort(ip.begin(),ip.end()); 
        vector<pair<int,int>> result;
        int n = ip.size();
        // n since every element visted exactly once
        for(int i=0;i<n;i++){
            if(result.empty() || ip[i].first > result.back().second){
                result.push_back(ip[i]);
            }
            else{
                result.back().second = max(result.back().second, ip[i].second);
            }
        }
        return result;
    }
};

int main(void){
    vector<pair<int,int>> ip = {{1,3},{2,4},{4,6},{8,10},{9,11},{8,11},{16,18},{15,17}};
    // auto S = BruteForceApproach();
    auto S = OptimisedSolution();
    auto result = S.solve(ip);
    for(auto &i: result){
        cout << i.first << " " << i.second << endl;
    }
}