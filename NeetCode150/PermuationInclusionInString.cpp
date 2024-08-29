/*
* LeetCode Question: 567 Permutation in string
@param strings, s1 and s2

todo: Here we need to return true if the permutation of s1 appears in s2 or in otherwords, s2 contains permutation of s1.
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

/*
* Approach : Brute Force Solution
@params s1: string, s2: string
- If the size of s1 > s2 then return false since We are checking permutation of s1 inside the s2
- Get all the possible permutation of the string.
- Run a loop across the permutation array:
    - If s2 contains the string then return true
- return false at the end

? Time Complexity: O(n!)
? Space Complexity: O(n!)
- where n is length of subString
! Worst Possible Solution
*/
class BruteForceSolution{
    vector<string> getPermutation(string s){
        vector<string> answer;
        sort(s.begin(),s.end());
        do{
            answer.push_back(s);
        }while(next_permutation(s.begin(),s.end()));
        return answer;
    }
public:
    bool checkInclusion(string s1, string s2){
        if(s1.size()>s2.size()){
            return false;
        }
        vector<string> permutationS1 = getPermutation(s1);
        for(string str: permutationS1){
            if(s2.find(str) != string::npos){
                return true;
            }
        }
        return false;
    }
};
/*
* Approach-2: Sliding Window
@param s1: String and s2: String
- Initialise the array to store the count of characters in the string,  count1 and count2
- loop through first string to store the count of characters in array, count1
- the window length would be equal to length of first string
- We implement a sliding window to check all the substrings
- Loop:
    - We make sure the count2 is filled with all 0
    - then we store the count of characters in the window string in the count2
    - then we check whether or not two arays are equal or not, If true return true
- at the end return false

? Time complexity: O(n*m)
? Space complexity: O(1)
*/
class Approach2SlidingWindow {
    bool checkEqual(int arr1[26], int arr2[26]){
        for(int i=0;i<26;i++){
            if(arr1[i] != arr2[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        int count1[26] = {0};
        int count2[26] = {0};

        for(char c : s1){
            count1[c-'a']++;
        }

        int i = 0;
        int j;
        int window = s1.length();
        int index;
        int len_s2 = s2.length();
        while(i <= len_s2-window){
            fill(begin(count2),end(count2),0);
            j = 0;
            while(j < window){
                index = s2[i+j] - 'a';
                count2[index]++;
                j++;
            }
            if(checkEqual(count1,count2)){
                return true;
            }
            i++;
        }

        return false;
    }
};


/*
* Approach3: Sliding Window wih Two Pointer
! Instead of updating the entire count2 array on each window, we only update the changed part in the count2 array
- Initialise the count1 and count2 array of size 26
- Store the s1 character count in count1
- Then we initialise two pointer i and j, and window length
- We run the loop with i<=j and j<len og s2
    - if j-i >= wndow:
        - We remove the element at ith index from count2 array and increment the i
    - We add the element at jth index
    - we check whether count1 and count2 are equal: If true, return true;
    - j++
- return false at the end of program
? Time Complexity: O(n+m) where n is the length of s2 and m is length of s1
? Space Complexity: O(1)
*/
class mostOptimisedApproach{
    bool checkEqual(int count1[26], int count2[26]){
        for(int i=0;i<26;i++){
            if(count1[i] != count2[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2){
        if(s1.size() > s2.size()){
            return false;
        }
        int count1[26] = {0};
        int count2[26] = {0};
        for(char c : s1){
            count1[c-'a']++;
        }
        int i=0;
        int j=0;
        int window = s1.length();
        int len_s2 = s2.length();
        while(j < len_s2 && i<=j){
            if(j-i >= window){
                count2[s2[i]-'a']--;
                i++;
            }
            count2[s2[j]-'a']++;
            if(checkEqual(count1, count2)){
                return true;
            }
            j++;
        }
        return false;  
    }
};

int main(void){
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << boolalpha << mostOptimisedApproach().checkInclusion(s1,s2) << endl;
}