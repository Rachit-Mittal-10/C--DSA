#include<iostream>
using namespace std;

// In this Method, We check the binary representation of a number.

// for example
// 8 = 1000 : This is power of two since there is only 1 set bit at place of 2^3

int main(){
	int n,ctr = 0;
	cin >> n;
	while(n!=0){
		if((n&1)==1) ctr++;
		n = n >>1;
	}
	if(ctr == 1){
		cout << "Power of 2";
	}
	else{
		cout << "not a power of 2";
	}
	return 0;
}