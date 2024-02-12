#include<iostream>
using namespace std;

int GetMax(int Arr[],int len){
    int max_ = INT_MIN;
    for(int i=0;i<len;i++){
        max_ = max(max_,Arr[i]);    // Inbuilt Function that returns the maximum value of two
        // if(Arr[i]>max){
        //     max = Arr[i];
        // }
    }
    return max_;
}

int GetMin(int Arr[],int len){
    int min_ = INT_MAX;
    for(int i=0;i<len;i++){
        min_ = min(min_,Arr[i]);    //Inbuilt Function that returns the minimum value of two
        // if(min_>Arr[i]){
        //     min_  = Arr[i];
        // }
    }
    return min_; 
}
// min max in Array
int main(){
    int Array[] = {11,7,1,4,6,2,10,3,0};
    int len =  sizeof(Array)/sizeof(int);
    int max = GetMax(Array,len), min  = GetMin(Array,len);
    cout << max << "|" << min << endl;
    return 0;
}