/*
Question Link: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

Approach: 
Maintain a map of count of variable.
Maintain a queue of visiting of non repeating character.

If repeating character then pop it from queue.

*/


#include<bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A)
{
    // Code here
    map<char, int> count;
    queue<char> q;
    int size = A.length();
    string result;
    for (auto ch : A)
    {
        count[ch]++;
        q.push(ch);
        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                result += q.front();
                break;
            }
        }
        if (q.empty())
        {
            result += '#';
        }
    }

    return result;
}


int main(){
    cout << FirstNonRepeating("aabc") << endl;
    return 0;
}