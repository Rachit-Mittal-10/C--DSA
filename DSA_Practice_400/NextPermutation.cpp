#include<iostream>
#include<vector>
#include"../Print.hpp"
using namespace std;

class OptimisedSolution{
    void reverse(vector<int>& arr, int start, int end){
        while(start <= end){
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
    }
public:
    void solve(vector<int>& arr){
        int n = arr.size();
        int index = -1;
        for(int i=n-2;i>=0;i--){
            if(arr[i] < arr[i+1]){
                index = i;
                break;
            }
        }
        if(index == -1){
            reverse(arr,0,n-1);
            return;
        }
        for(int i=n-1;i>index;i--){
            if(arr[i] > arr[index]){
                swap(arr[i],arr[index]);
                break;
            }
        }
        reverse(arr,index+1,n-1);
    }
};

int main(void){
    vector<int> arr = {2,1,5,4,3,0,0};
    auto S = OptimisedSolution();
    S.solve(arr);
    Print(arr);
}