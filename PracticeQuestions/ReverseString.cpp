#include<bits/stdc++.h>
using namespace std;

void Reverse(char arr[],int n){
    int s = 0;
    int e = n-2;

    while(s<e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}

int main(){
    char arr[7] = "Rachit";
    Reverse(arr,7);
    cout << arr << endl;
    return 0;
}