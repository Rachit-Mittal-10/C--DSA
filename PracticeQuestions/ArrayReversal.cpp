// Array Reversal

#include<iostream>
using namespace std;

void printArray(int Arr[],int len){
	for(int i=0;i<len;i++){
		cout << Arr[i] << " ";
	}
	cout << endl;
}

// Method-1 to Reverse Array
void Reverse_Array(int Arr[],int len){
	for(int i=0;i<len/2;i++){
		swap(Arr[i],Arr[len-i-1]);
	}
}
// Method 2 to Reverse Array
void Reverse_Array_2(int Arr[], int len){
	int start = 0;
	int end = len-1;
	while(start<end){
		swap(Arr[start],Arr[end]);
		start++;
		end--;
	}
}

int main(){
	int Arr[] = {1,5,8,4,6};
	int len = sizeof(Arr)/sizeof(int);
	cout << "Array before Reversal" << endl;
	printArray(Arr,len);
	// Reverse_Array(Arr,len);
	Reverse_Array_2(Arr,len);
	cout << "Array after Reversal" << endl;
	printArray(Arr,len);
	return 0;
}