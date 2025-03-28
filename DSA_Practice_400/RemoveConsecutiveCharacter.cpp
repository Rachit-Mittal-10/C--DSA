#include<bits/stdc++.h>
using namespace std;

class Solution{    
public:
    string solve(string s1){
        string ans = "";
        ans += s1[0];
        for(int i=1;i<s1.size();i++){
            if(s1[i] != s1[i-1]){
                ans += s1[i];
            }
        }
        return ans;
    }
};
int main(void){
    auto S = Solution();
    cout << S.solve("ABAAA") << endl;
    return 0;
}