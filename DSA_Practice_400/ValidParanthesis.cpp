#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool solve(string s){
        int n = s.size();
        stack<char> stk;
        for(int i=0;i<n;i++){
            char c = s[i];
            if(c=='(' || c=='[' || c=='{'){
                stk.push(c);
                continue;
            }
            else{
                if(stk.empty()){
                    return false;
                }
                if((c==']' && stk.top()=='[') || (c=='}' && stk.top()=='{') || (c==')' && stk.top()=='(')){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(stk.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(void){
    string s = "(])";
    auto A = Solution();
    cout << boolalpha << A.solve(s) << endl;
    return 0;
}