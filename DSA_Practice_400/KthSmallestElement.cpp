#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class HeapSolution{
public:
    int getMin(vector<int>& arr, int K){
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(auto i:arr){
            minHeap.push(i);
        }
        for(int i=0;i<K-1;i++){
            minHeap.pop();
        }
        return minHeap.top();
    }
};

int main(void){
    vector<int> arr = {4,2,1,5,3,6};
    auto S = HeapSolution();
    cout << S.getMin(arr,2) << endl;
}