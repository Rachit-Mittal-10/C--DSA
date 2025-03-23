#include<iostream>
#include<vector>
using namespace std;

class BruteForceApproach{
    int count(vector<int>& arr, int a){
        int c = 0;
        for(auto i: arr){
            if(i == a){
                c++;
            }
        }
        return c;
    }
public:
    pair<int,int> solve(vector<int>& arr, int n){
        pair<int,int> result = {-1,-1};
        for(int i=1;i<=n;i++){
            int temp = count(arr,i);
            if(temp == 2){
                result.first = i;
            }
            else if(temp == 0){
                result.second = i;
            }
            if(result.first != -1 && result.second != -1){
                break;
            }
        }
        return result;
    }
};

class HashArrayApproach{public:
    pair<int,int> solve(vector<int>& arr, int n){
        vector<int> hashArr(n+1,0);
        for(auto i:arr){
            hashArr[i]++;
        }
        pair<int,int> result = {-1,-1};
        for(int i=1;i<=n;i++){
            if(hashArr[i] == 2){
                result.first = i;
            }
            else if(hashArr[i] == 0){
                result.second = i;
            }
        }
        return result;
    }
};

int main(void){
    vector<int> arr = {3,1,2,5,3};
    // auto S1 = BruteForceApproach().solve(arr,5);
    auto S2 = HashArrayApproach().solve(arr,5);
    // cout << S1.first << " " << S1.second << endl;
    cout << S2.first << " " << S2.second << endl;
}