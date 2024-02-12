/*
LeetCode Question: 26
Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

Approach::
:We use two pointers. One Pointer for each string.
We traverse through haystack string. If character matched at pointers then We increase the value of pointer in needle string too.
If there is fail then we move haystack pointer to next of previous start. Needle Pointer to 0.
*/


#include<bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
    int index_haystack = 0;
    int index_needle = 0;
    int len_haystack = haystack.size();
    int len_needle = needle.size();

    while(index_haystack < len_haystack && index_needle < len_needle){
        if(haystack[index_haystack] == needle[index_needle]){
            index_needle++;
        }
        else{
            index_haystack = index_haystack - index_needle;
            index_needle = 0;
        }
        index_haystack++;

        if(index_needle == len_needle){
            return index_haystack-len_needle;
        }
    }
    return -1;
}

int main(){
    int k = strStr("mississippi","issip");
    return 0;
}