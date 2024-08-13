#include<iostream>
#include<cctype>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
    bool isAlNum(char ch){
        return isalnum(static_cast<unsigned>(ch));
    }
public:
    bool isPalindrome(string s){
        int start = 0;
        int end = s.size()-1;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        while(start<=end){
            if(!isAlNum(s[start])){
                start++;
                continue;
            }
            if(!isAlNum(s[end])){
                end--;
                continue;
            }
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

int main(void){
    string s = "0P";
    cout << boolalpha << Solution().isPalindrome(s) << endl;
    return 0;
}