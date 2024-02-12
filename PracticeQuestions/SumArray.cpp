#include<iostream>
using namespace std;
// sum of all elements in array

int sum(int arr[],int len){
	int sum  = 0;
	for(int i = 0;i<len;i++){
		sum += arr[i];
	}
	return sum;
}

int main(){
	int num[] = {1,2,3,4,5,6};
	int len = sizeof(num)/sizeof(int);
	cout << sum(num,len);
	return 0;
}