/*
*LeetCode Question Number 3

todo Find the length of longest substring without repeating character
*/
#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int n = s.size();
        int right;
        int maxSize = 0;
        unordered_set<char> temp;
        for(right=0;right<n;right++){
            while(temp.find(s[right]) != temp.end()){
                temp.erase(temp.find(s[left]));
                left++;
            }
            temp.insert(s[right]);
            maxSize = max(maxSize,right-left+1);
        }
        return maxSize;
    }
};

int main(void){
    cout << Solution().lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}