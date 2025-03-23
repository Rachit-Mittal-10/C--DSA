#include<vector>
#include<iostream>
#include<queue>
using namespace std;

class MaxHeapSolution{
public:
    int getKLargest(vector<int>& arr, int k){
        priority_queue<int> maxHeap;
        for(auto i:arr){
            maxHeap.emplace(i);
        }
        for(int i=0;i<k-1;i++){
            maxHeap.pop();
        }
        return maxHeap.top();
    }
};

int main(void){
    vector<int> arr = {4,5,1,6,2};
    int K = 2;
    auto S = MaxHeapSolution();
    cout << S.getKLargest(arr,K) << endl;
    
}