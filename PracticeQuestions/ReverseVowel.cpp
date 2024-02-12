/*
Question Link: https://leetcode.com/problems/reverse-vowels-of-a-string/
*/
#include<bits/stdc++.h>
using namespace std;

string reverseVowels(string s) {
    unordered_set<char> vowel = {'a','e','i','o','u','A','E','I','O','U'};

    int start = 0;
    int end = s.size()-1;

    while(start<end){
        if(vowel.count(s[start])!=0 && vowel.count(s[end])!=0){
            swap(s[start],s[end]);
            start++;
            end--;
        }
        else if(vowel.count(s[start])!=0 && vowel.count(s[end])==0){
            end--;
        }
        else if(vowel.count(s[start])==0 && vowel.count(s[end])!=0){
            start++;
        }
        else{
            start++;
            end--;
        }
    }
    return s;
}

int main(){
    cout << reverseVowels("Hello") << endl;
    return 0;
}