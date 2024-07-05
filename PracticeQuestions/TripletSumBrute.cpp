#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printVector(vector<vector<int>> arr, int len){
    for(int i = 0;i<len;i++){
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j] << " ";
        }cout << endl;
    }
}


// Code Stuio(Coding Ninjas) Triplet Sum Brute Force
int main(){
    int arr[] = {-26,32,4,17,-16,18,1,8,6,8,3,-13};
    int K;
    cin >> K;
    vector<vector<int>> ans;
    int l = sizeof(arr)/sizeof(int);
    for(int i=0;i<l;i++){
        for(int j=i+1;j<l;j++){
            for(int k=j+1;k<l;k++){
                if((arr[i]+arr[j]+arr[k])==K){
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    sort(temp.begin(),temp.end());
                    if(count(ans.begin(),ans.end(),temp)==0){
                        ans.push_back(temp);
                    }
                }
            }
        }
    }
    int len = ans.size();
    printVector(ans,len);
    return 0;

}