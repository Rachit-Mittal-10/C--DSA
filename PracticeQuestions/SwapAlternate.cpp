// Swap Alternate

//Odd Number of Elements
// i/p ---> arr[5] = {1,2,3,4,5}
// o/p --->  {2,1,4,3,5}
// in this loops ran till indexs value 3

// Even No of Elements
// i/p ---> arr[5] = {1,2,3,4,5,6}
// o/p --->  {2,1,4,3,6,5}
// in this case loop run till index value 4

// So Loop will run till len-2

#include<iostream>
using namespace std;

void PrintArray(int Arr[],int len){
	for(int i=0;i<len;i++){
		cout << Arr[i] << " ";
	}
	cout << endl;
}


// Logic of Swap
// void swap(int *num1,int *num2){
// 	int temp = *num1;
// 	*num1 = *num2;
// 	*num2 = temp;
// }

void Swap_Alternate(int Arr[],int len){
	int i = 0;
	while(i<=len-2){
		swap(Arr[i],Arr[i+1]);	// There is anpre-defined function swap in C++
		i += 2;
	}
}

int main(){
	int Arr[] = {1,2,3,4,5};
	int len = sizeof(Arr)/sizeof(int);

	cout << "Array Before Swap Alternate Function Call" << endl;
	PrintArray(Arr,len);

	Swap_Alternate(Arr,len);
	
	cout << "Array After Swap Alternate Function Call" << endl;
	PrintArray(Arr,len);
	return 0;
}