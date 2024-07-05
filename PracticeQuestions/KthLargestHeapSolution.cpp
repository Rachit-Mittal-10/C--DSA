#include<bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k){
	int n = arr.size();
	vector<int> sum_array;
	for(int i=0;i<n;i++){
		int sum = 0;
		for(int j=i;j<n;j++){
			sum += arr[j];
			sum_array.push_back(sum);
		}
	}
	sort(sum_array.begin(),sum_array.end());
	int n2 = sum_array.size();
	return sum_array[n2-k];
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    cout << getKthLargest(arr,2) << endl;
    return 0;
}