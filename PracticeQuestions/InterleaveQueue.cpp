/*
Question Link: https://practice.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
Solution: https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/#practice
*/

class Approach1{
    // TC: O(N)
    // SC: O(N)
public:
    vector<int> rearrangeQueue(queue<int> &q){
        vector<int> answer;
        if(q.size()%2!=0){
            return answer;
        }
        queue<int> temp;
        int half = q.size()/2;
        
        for(int i=0;i<half;i++){
            temp.push(q.front());
            q.pop();
        }
        
        while(!temp.empty()){
            answer.push_back(temp.front());
            temp.pop();
            answer.push_back(q.front());
            q.pop();
        }
        
        return answer;       
    }
};