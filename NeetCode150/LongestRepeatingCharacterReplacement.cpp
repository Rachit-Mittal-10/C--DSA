/*
*LeetCode Question 424: Longest Repeating Character Replacement
todo: Given a string s and integer k, you can choose any character of string and choose to replace it k times atmost. Return the length of longest repeating substring containing the character after performing the operations.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;

class BruteForceSolution{
    /*
    ! Time Complexity: O(n^2)
    ! Space Complexity: O(2^n - 1) ---> Too much Memory

    * Approach:
    - Iterate through the string and generate all the substring possible. Store the substring in the vector.
    - for each substring in the vector:
        - find the count of each element and maximum frequency element.
        - if size - maxFrequency is less than k then update the maxSize
    - return maxSize
    */
public:
    int longestRepeatingCharacter(string s, int k){
        vector<string> substringsAll;
        int n = s.size();
        for(int i=0;i<n;i++){
            string substring = "";
            for(int j=i;j<n;j++){
                substring += s[j];
                substringsAll.push_back(substring);
            }
        }
        int maxSize = INT_MIN;
        for(string str:substringsAll){
            vector<int> count(26,0);
            int size = str.size();
            for(char c:str){
                count[c-'A']++;
            }
            int maxElement = *max_element(count.begin(),count.end());
            if(size-maxElement <= k){
                maxSize = max(maxSize,size);
            }
        }
        return maxSize;
    }
};

class SpaceOptimisedWay{
    /*
    ! Time Complexity: O(N^2)
    ! Space Compexity: O(26)

    *Approach
    - Same as previous but with a change that merge the second loop to first loop. Count the frequency as you make substrings. Check for validity along.
    */
public:
    int longestRepeatingCharacter(string s, int k){
        int n = s.size();
        int maxSize = INT_MIN;
        for(int i=0;i<n;i++){
            string substring = "";
            vector<int> count(26,0);
            int subStrSize = 0;
            for(int j=i;j<n;j++){
                substring += s[j];
                subStrSize++;
                count[s[j]-'A']++;
                int maxElement = *max_element(count.begin(), count.end());
                if(subStrSize - maxElement <= k){
                    maxSize = max(maxSize, subStrSize);
                }
                else{
                    break;
                }
            }
        }
        return maxSize;
    }
};

class MostOptimisedWay{
    /*
    ! Time Complexity: O(N)
    ! Space Complexity: O(26)

    * Approach
    - Two Point Approach with slighting window
    - Initialise a left and right points. 
    - Increase the frequency of the character.
    - Get the max Frequency.
    - Check for validity of the substring i.e changes to be made should be less than k. Write a while loop in case, substring is invalid. This will move the left pointer and update the count vector and maxFrequency.
    - If valid then, maxSize = max(maxSize, r-l+1)
    - length of substring at a moment is r-l+1.
    */
public:
    int longestRepeatingCharacter(string s, int k){
        vector<int> count(26,0);
        int maxSize = INT_MIN;
        int maxFrequency = 0;
        int n = s.size();
        int l = 0;
        int r = 0;
        while(r<n){
            count[s[r]-'A']++;
            maxFrequency = *max_element(count.begin(),count.end());
            while( (r-l+1) - maxFrequency > k ){
                count[s[l++]-'A']--;
                maxFrequency = *max_element(count.begin(),count.end());
            }
            if((r-l+1)-maxFrequency <= k){
                maxSize = max(maxSize, r-l+1);
            }
            r++;
        }
        return maxSize;
    }
};

int main(void){
    string S = "AABABBA";
    int k = 2;
    cout << BruteForceSolution().longestRepeatingCharacter(S,k) << endl;
    cout << SpaceOptimisedWay().longestRepeatingCharacter(S,k) << endl;
    cout << MostOptimisedWay().longestRepeatingCharacter(S,k) << endl;
    return 0;
}