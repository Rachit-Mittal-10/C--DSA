/*
Question Link: https://practice.geeksforgeeks.org/problems/queue-reversal/1
*/

// Recursive Approach
//TC: O(N)
//SC: O(1)
class Solution1
{
    public:
    queue<int> rev(queue<int> q)
    {
        // add code here.
        if(q.empty()){
            return q;
        }
        int temp = q.front();
        q.pop();
        q = rev(q);
        q.push(temp);
        return q;
    }
};


// Reversal by Stack
//TC: O(N)
//SC: O(N)
class Solution2
{
    public:
    queue<int> rev(queue<int> q)
    {
        // add code here.
        stack<int> reverse;
        int temp;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            reverse.push(temp);
        }
        
        while(!reverse.empty()){
            temp = reverse.top();
            reverse.pop();
            q.push(temp);
        }
        return q;
    }
};