#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool solve(string s){
        int start = 0;
        int end = s.size()-1;
        while(start <= end){
            if(!isalnum(s[start])){
                start++;
                continue;
            }
            if(!isalnum(s[end])){
                end--;
                continue;
            }
            if(tolower(s[start]) != tolower(s[end])){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

int main(void){
    auto S = Solution();
    cout << boolalpha << S.solve("ABa") << endl;
    return 0;
}