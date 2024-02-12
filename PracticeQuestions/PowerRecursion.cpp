#include<bits/stdc++.h>
using namespace std;


int Power(int base, int exp){
    if(exp == 0){
        return 1;
    }
    if(exp == 1){
        return base;
    }
    int ans;
    int small= Power(base,exp/2);
    if(exp&1){
        ans = base*small*small;
    }else{
        ans = small*small;
    }
    return ans;
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << Power(a,b);
    return 0;
}