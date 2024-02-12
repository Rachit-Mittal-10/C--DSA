// Linear Search
/*
Steps: 
1. We compare key with each element of Array.
2. When found, We return with Index Value.
2.a. Otherwise, We return with -1.
*/

#include<iostream>
using namespace std;


//Linear Search Function
int lsearch(int Arr[],int len, int key){
    for(int i = 0;i<len;i++){
        if(key==Arr[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int Arr[] = {4,5,8,15,11};
    int len = sizeof(Arr)/sizeof(int);
    int key;
    cin >> key;
    int found = lsearch(Arr,len,key);
    if(found!=-1){
        cout << key << " found at Index-" << found << endl;
    } else{
        cout << key << " Not Availabe in Array" << endl;
    }
    return 0;
}