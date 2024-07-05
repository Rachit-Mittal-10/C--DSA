// Question Link: https://www.codingninjas.com/studio/problems/median-in-a-stream_975268?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<bits/stdc++.h>
using namespace std;

int signum(int a, int b){
	if(a == b){
        return 0;
    }
	else if(a > b){
        return 1;
    }
	else{
        return -1;
    }
}

void call_median(int element,priority_queue<int>& maxHeap,priority_queue<int,vector<int>,greater<int>>& minHeap, int& median){
	switch(signum(maxHeap.size(),minHeap.size())){
		case 0: // Size of Min Heap = Size of Max Heap = n
			if(element <= median){
				// Maxheap mei insert
				maxHeap.push(element);
				median = maxHeap.top();
			}else{
				// MinHeap mei insert
				minHeap.push(element);
				median = minHeap.top();
			}
			break;
		case 1: // Size of Min Heap < Size of Max Heap
			if(element <= median){
				// MaxHeap mei insert
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(element);
			}else{
				// MinHeap mei insert
				minHeap.push(element);
			}
			median = (minHeap.top() + maxHeap.top())/2;
			break;
		case -1: // Size of Min Heap > Size of Max Heap
			if(element <= median){
				// Max Heap mei insert
				maxHeap.push(element);
			}else{
				// Min Heap mei insert
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(element);
			}
			median = (minHeap.top() + maxHeap.top())/2;
			break;
	}
	return;
}

vector<int> findMedian(vector<int> &arr, int n){
	// Write your code here
	vector<int> answer;
	priority_queue<int> maxHeap;
	priority_queue<int,vector<int>,greater<int>> minHeap;
	int median = 0;
	for(int i=0;i<n;i++){
		call_median(arr[i],maxHeap,minHeap,median);
		answer.push_back(median);
	}
	return answer;
}

int main(){
    vector<int> arr = {1,3,5,8};
    vector<int> result;
    result = findMedian(arr,arr.size());
    return 0;
}