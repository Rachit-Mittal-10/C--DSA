/*
Sort 0 1 2 using Dutch National Flag Algo
Based on fact that index
0 to low-1 had 0 as element
low to high-1 had 1 as element
and high to len-1 had 2 as element
*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr, int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }cout << endl;
}

int main(void){
    vector<int> arr_012 = {0,1,2,0,1,2};
    int len = arr_012.size();
    int low = 0, mid = 0, high = len-1;
    while(mid<=high){
        switch(arr_012[mid]){
            case 0:{
                swap(arr_012[mid],arr_012[low]);
                low++;
                mid++;
                break;
            }
            case 1:{
                mid++;
                break;
            }
            case 2:{
                swap(arr_012[mid],arr_012[high]);
                high--;
                break;
            }
        }
    }

    printVector(arr_012,len);
}