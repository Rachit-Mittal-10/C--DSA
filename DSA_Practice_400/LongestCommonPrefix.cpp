#include<bits/stdc++.h>
using namespace std;

class BruteForce{
public:
    string solve(vector<string>& arr){
        sort(arr.begin(),arr.end());
        int n = arr.size();
        string s1 = arr[0];
        string s2 = arr[n-1];
        string result = "";
        int n2 = s1.size();
        for(int i=0;i<n2;i++){
            if(s1[i] != s2[i]){
                break;
            }
            result += s1[i];
        }
        return result;
    }
};


int main(void){
    auto S = BruteForce();
    vector<string> arr = {"flying","flea","flower"};
    cout << S.solve(arr) << endl;
    return 0;
}