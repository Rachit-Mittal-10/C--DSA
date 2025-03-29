#include<bits/stdc++.h>
using namespace std;

class Solution{
    vector<string> mapping = {"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777","7777","8","88","888","9","99","999","9999"};
public:
    string solve(string s){
        string result = "";
        for(auto c:s){
            if(c == ' '){
                result += '0';
            }
            else{
                result += mapping[c-'A'];
            }
        }
        return result;
    }
};

int main(void){
    cout << Solution().solve("GFG") << endl;  
    return 0;
}