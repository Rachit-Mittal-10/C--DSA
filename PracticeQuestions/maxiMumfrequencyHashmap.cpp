#include<bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here
    map<int,int> m;

    for(int i=0;i<n;i++){
        if(m.count(arr[i]) == 0){
            m[arr[i]] = 1;
        }else{
            m[arr[i]]++;
        }
    }

    map<int,int> :: iterator it = m.begin();
    int largest = it->second;
    int answer = it->first;
    it++;
    while(it != m.end()){
        if(it->second > largest){
            answer = it->first;
            largest = it->second;
        }
        it++;
    }
    return answer;
}

int main(void){
	vector<int> arr = {4,5,-1};

	cout << maximumFrequency(arr,3) << endl;
	return 0;
}