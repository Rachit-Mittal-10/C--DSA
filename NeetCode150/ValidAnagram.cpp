/*

Return true if s and t are Valid Anagrams otherwise false
LeetCode Question: 242

Anagram is basically a word which is made by rearranging of character in word i.e. both word uses same characters in same frequency

*/


#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

bool checkAnagram(string S, string T);
bool checkAnagram2(string S, string T);

int main(void){
    cout << boolalpha << checkAnagram("abab","babb") << endl;
    cout << boolalpha << checkAnagram2("abab","baba") << endl;
    return 0;
}
/*

In this approach, We create a map from one string storing the amount of character present in string and compare that data with other string

Time Complexity: O(S+T)
- Since we traverse both the string exactly once

Space Complexity: O(S)
- Since we storing the count of one string in hashmap

*/
bool checkAnagram(string S, string T){
    // If size not equal then it cannot be anagram.
    if(S.size() != T.size()){
        return false;
    }
    unordered_map<char, int> mp;
    // We store the count by traversing the string
    for(auto ch:S){
        mp[ch]++;
    }
    for(auto ch:T){
        // If character not found in mp, Not Anagram
        if(mp.find(ch) == mp.end()){
            return false;
        }
        // If unequal count, then not an Anagram
        else if(mp[ch]==0){
            return false;
        }
        // Subtract count when character found
        else{
            mp[ch]--;
        }
    }
    return true;
}

bool checkAnagram2(string S, string T){
    if(S.size() != T.size()){
        return false;
    }
    string sortedS = S;
    sort(sortedS.begin(), sortedS.end());
    string sortedT = T;
    sort(sortedT.begin(), sortedT.end());
    return sortedS == sortedT;
}