#include<bits/stdc++.h>
using namespace std;

class Solution { 
public:
    int lengthOfLongestSubstring(string s) {
        int MAX_LEN = 0;
        int len = 0;
        map<char,int> mp;
        int n = s.size();
        int i=0, j=0;
        while(i<n && j<n){
            if(mp.find(s[j]) != mp.end()){
                i=mp[s[j]]+1;
                mp.clear();
                j=i;
                len=0;
            }
            else{
                mp[s[j]] = j;
                j++;
                len++;
            }
            MAX_LEN=max(MAX_LEN,len);
        }
        return MAX_LEN;
    }

    int lengthOfLongestSubstring2(string s){
        int MAX_LEN = 0;
        int len = 0;
        map<char,int> mp;
        int n = s.size();
        int i=0, j=0;
        while(i<n&&j<n){
            if(mp.find(s[j]) != mp.end()){
                i=max(i,mp[s[j]]+1);
            }
            mp[s[j]] = j;
            MAX_LEN = max(MAX_LEN,j-i+1);
            j++;
        }
        return MAX_LEN;
    }
};

int main(void){
    auto S = Solution();
    // cout << S.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << S.lengthOfLongestSubstring2("aab") << endl;
    return 0;
}