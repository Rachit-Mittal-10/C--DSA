/*
Question Link: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
*/

class Solution
{
    // TC(Worst Case) : O(N*K)
    // SC: O(N)
    int max_element_queue(deque<int> window){
        deque<int> max;
        while(!window.empty()){
            int element = window.front();
            if(max.empty()){
                max.push_front(element);
            }else{
                int front = max.front();
                if(element>front){
                    max.push_front(element);
                }
            }
            window.pop_front();
        }
        return max.front();
    }
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> answer;
        deque<int> window;
        for(int i=0;i<k;i++){
            window.push_back(arr[i]);
        }
        int max_ele = max_element_queue(window);
        answer.push_back(max_ele);
        for(int i=k;i<n;i++){
            if(arr[i] > max_ele){
                window.pop_front();
                window.push_back(arr[i]);
                max_ele = arr[i];
                answer.push_back(max_ele);
            }else{
                if(window.front() == max_ele){
                    window.pop_front();
                    window.push_back(arr[i]);
                    max_ele = max_element_queue(window);
                    answer.push_back(max_ele);
                }else{
                    window.pop_front();
                    window.push_back(arr[i]);
                    answer.push_back(max_ele);
                }
            }
        }
        return answer;
    }
};