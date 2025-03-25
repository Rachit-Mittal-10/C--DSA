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

class SpaceOptimised{
    int sumN(int n){
        return n*(n+1)/2;
    }
    int sumSquaredN(int n){
        return n*(2*n+1)*(n+1)/6;
    }
    int arraySum(vector<int>& arr){
        int sum = 0;
        for(auto i:arr){
            sum += i;
        }
        return sum;
    }
    int arraySquaredSum(vector<int>& arr){
        int sum=0;
        for(auto i:arr){
            sum += i*i;
        }
        return sum;
    }
public:
    pair<int,int> solve(vector<int>& arr, int n){
        int t1 = sumN(n);
        int t2 = sumSquaredN(n);
        int t3 = arraySum(arr);
        int t4 = arraySquaredSum(arr);

        //  A-B
        int t5 = t1-t3;
        int t6 = t2-t4;
        // A+B
        int t7 = t6/t5;
        // A repeating
        // B missing
        int t8 = (t5+t7)/2;
        int t9 = (t7-t5)/2;
        return make_pair(t8,t9);
    }
};

int main(void){
    vector<int> arr = {3,1,2,5,3};
    // auto S1 = BruteForceApproach().solve(arr,5);
    auto S2 = HashArrayApproach().solve(arr,5);
    auto S3 = SpaceOptimised().solve(arr,5);
    cout << S2.first << " " << S2.second << endl;
    cout << S3.first << " " << S3.second << endl;
}