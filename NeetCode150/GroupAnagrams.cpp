/*
LeetCode Question: 49
Here we need to group the anagrams
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../Print.hpp"
#include<unordered_map>
#include<chrono>
using namespace std;

/*
This builds upon Valid Anagram.
Approach:
- Initialise answer
- Run a loop across vectors
    - Run another loop
        - Check if two are anagrams.
        - Add to temp
    -  Add temp to answer
*/

class Method1
{
    // TC: O(KlogK)
    // K is length of string
    bool ValidAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        auto sortedS = s;
        sort(sortedS.begin(), sortedS.end());
        auto sortedT = t;
        sort(sortedT.begin(), sortedT.end());
        return sortedS == sortedT;
    }
    // Time Complexity: O(N^2 * KlogK)
    vector<vector<string>> GroupAnagram(vector<string> anagrams)
    {
        vector<vector<string>> answer;
        int n = anagrams.size();
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                continue;
            }
            vector<string> temp;
            auto s = anagrams[i];
            visited[i] = true;
            temp.push_back(s);
            for (int j = i + 1; j < n; j++)
            {
                if (visited[j])
                {
                    continue;
                }
                auto t = anagrams[j];
                if (ValidAnagram(s, t))
                {
                    temp.push_back(t);
                    visited[j] = true;
                }
            }
            answer.push_back(temp);
        }
        return answer;
    }

public:
    vector<vector<string>> getGroupAnagram(vector<string> anagram)
    {
        return GroupAnagram(anagram);
    }
};

class Method2
{
    // TC: O(K)
    // K is length of string
    bool ValidAnagram(string S, string T)
    {
        if (S.size() != T.size())
        {
            return false;
        }
        unordered_map<char, int> mp;
        for (auto ch : S)
        {
            mp[ch]++;
        }
        for (auto ch : T)
        {
            if (mp.find(ch) == mp.end())
            {
                return false;
            }
            else if (mp[ch] == 0)
            {
                return false;
            }
            else
            {
                mp[ch]--;
            }
        }
        return true;
    }
    // Time Complexity: O(N^2 * K)
    vector<vector<string>> GroupAnagram(vector<string> anagrams)
    {
        vector<vector<string>> answer;
        int n = anagrams.size();
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                continue;
            }
            vector<string> temp;
            auto s = anagrams[i];
            visited[i] = true;
            temp.push_back(s);
            for (int j = i + 1; j < n; j++)
            {
                if (visited[j])
                {
                    continue;
                }
                auto t = anagrams[j];
                if (ValidAnagram(s, t))
                {
                    temp.push_back(t);
                    visited[j] = true;
                }
            }
            answer.push_back(temp);
        }
        return answer;
    }

public:
    vector<vector<string>> getGroupAnagram(vector<string> anagram)
    {
        return GroupAnagram(anagram);
    }
};

/*
Approach2:
- initialise a map
- initialise answer
- for i = 0 to n:
    - key = sorted ith element
    - if key present then add element to vector associated with key
    - else make empty array, add element add vector to map with key
- for key in map:
    - answer.push_back(mp[key])
*/

class Method3{
    // Time Complexity: O(NKlogK)
    // N is numnber of strings in vector
    // K is length of string in vector
    vector<vector<string>> GroupAnagram(vector<string> anagram){
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> answer;
        for(auto i:anagram){
            auto key = i;
            sort(key.begin(),key.end());    // This step take KlogK time
            if(mp.find(key) != mp.end()){
                mp[key].push_back(i);
            }
            else{
                vector<string> temp = {i};
                mp[key] = temp;
            }
        }
        for(auto t:mp){
            answer.push_back(t.second);
        }
        return answer;
    }
public:
    vector<vector<string>> getGroupAnagram(vector<string>& anagram){
        return GroupAnagram(anagram);
    }
};

int main(void)
{
    vector<vector<string>> answer;
    vector<string> anagram = {"ate", "tea", "eat", "tan", "nat", "bat", "atb","tab","eta","hut","tuh","aba","baa","aab","i"};
    auto s1 = chrono::high_resolution_clock::now();
    answer = Method1().getGroupAnagram(anagram);
    auto e1 = chrono::high_resolution_clock::now();
    auto s2 = chrono::high_resolution_clock::now();
    answer = Method2().getGroupAnagram(anagram);
    auto e2 = chrono::high_resolution_clock::now();
    auto s3 = chrono::high_resolution_clock::now();
    answer = Method3().getGroupAnagram(anagram);
    auto e3 = chrono::high_resolution_clock::now();
    auto t1 = chrono::duration_cast<chrono::nanoseconds>(e1-s1).count();
    auto t2 = chrono::duration_cast<chrono::nanoseconds>(e2-s2).count();
    auto t3 = chrono::duration_cast<chrono::nanoseconds>(e3-s3).count();
    cout << t1 << endl << t2 << endl << t3 << endl;
    // Print(answer);
    return 0;
}