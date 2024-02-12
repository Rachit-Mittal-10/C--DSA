#include<bits/stdc++.h>
using namespace std;
/*
This program find the HCF usimh Euclid Method
GCD(A,B) = GCD(A%B,B)
GCD(A,0) = A;
*/

int EuclidHCF(int num1,int num2){
    int HCF;
    if(num1 == 0){
        return num2;
    }
    else if(num2 == 0){
        return num1;
    }
    else{
        HCF = EuclidHCF(num2,num1%num2);
    }
    return HCF;
}
int main(){
    int num1, num2,HCF;
    cin >> num1 >> num2;
    if(num1 > num2){
        HCF = EuclidHCF(num1,num2);
    }else{
        HCF = EuclidHCF(num2,num1);
    }
    cout << HCF << endl;
    return 0;
}
