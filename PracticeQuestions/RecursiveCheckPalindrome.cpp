#include<bits/stdc++.h>
using namespace std;

bool CheckPalindrome(string& str, int start, int end){
    if(start > end) return true;

    if(str[start]!=str[end]){
        return false;
    }
    else{
        start++;
        end--;
        return CheckPalindrome(str,start,end);
    }
}

int main(){
    string pp = "ABCCA";
    cout << boolalpha << CheckPalindrome(pp,0,pp.size()-1);
    return 0;
}