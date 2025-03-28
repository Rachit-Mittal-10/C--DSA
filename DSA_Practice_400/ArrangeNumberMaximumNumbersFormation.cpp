#include<bits/stdc++.h>
using namespace std;

class Solution{
    static bool customComparator(const string& s1,const string& s2){
        return (s1+s2) > (s2+s1);
    }
public:
    string solve(vector<int>& arr){
        vector<string> temp;
        for(auto ele: arr){
            temp.push_back(to_string(ele));
        }
        sort(temp.begin(),temp.end(),customComparator);
        if(temp[0] == "0"){
            return "0";
        }
        string result = "";
        for(auto str: temp){
            result += str;
        }
        return result;
    }
};

int main(void){
    vector<int> nums = {9,5,34,30,3};
    cout << Solution().solve(nums) << endl;
}