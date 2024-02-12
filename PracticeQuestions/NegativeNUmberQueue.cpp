/*
Question Link: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
*/

class Approach1{
    /*
    Approach1: Sliding Window
    Create a window of K elements. Find the negative number in that window.
    Pop the first element and push an element from last in queue
    To find negative number,
        push and pop to find the negative number.
        While coming out of recursion back tracking of push operation
    Failing Reason: Recursion Tree getting incredibly complex causing segementation error.
    */
    int queuenegativenumber(deque<long long int> window){
        if(window.empty()){
            return 0;
        }
        int answer = 0;
        int temp = window.front();
        if(temp < 0){
            answer = temp;
        }else{
            window.pop_front();
            answer = queuenegativenumber(window);
            window.push_front(temp);
        }
        return answer;
    }
    void solve(long long int A[], long long int N, long long int K, vector<long long int>& answer){
        deque<long long int> window;
        for(int i=0;i<K;i++){
            window.push_back(A[i]);
        }
        int element = queuenegativenumber(window);
        answer.push_back(element);
        for(int i=K;i<N;i++){
            window.pop_front();
            window.push_back(A[i]);
            element = queuenegativenumber(window);
            answer.push_back(element);
        }
    }
    vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
        vector<long long int> answer;
        solve(A,N,K,answer);
        return answer;
    }
};

class Approach2{
    /*
    Approach2: Sliding Window without Recursion
    Push into window only if negative integer
    Push front element of window(0 if window is empty) into answer vector.
    Pop the negative integer at front if value at i-k equals the window front. 
    */
    vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
        deque<long long int> window;
        vector<long long int> answer;
        for(int i=0;i<K;i++){
            if(A[i]<0){
                window.push_back(A[i]);
            }
        }
        if(window.empty()){
            answer.push_back(0);
        }else{
            answer.push_back(window.front());
        }
        for(int i=K;i<N;i++){
            if(!window.empty() && window.front()==A[i-K]){
                window.pop_front();
            }
            
            if(A[i] < 0){
                window.push_back(A[i]);
            }
            
            if(window.empty()){
            answer.push_back(0);
            }else{
                answer.push_back(window.front());
            }
        }
        return answer;
    }
};