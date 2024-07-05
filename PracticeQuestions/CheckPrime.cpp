#include<iostream>
using namespace std;
// Checks whether the Number is Prime Nuber or Composite Number
int main(){
    int Num;
    cout << "Enter the Number: ";
    cin >>  Num;
    int ctr = 0;
    for(int i = 2;i<=Num-1;i++){
        if(Num%i==0){
            ctr++;
            break;
        }
    }
    if(ctr>0){
        cout << "Composite Number";
    }
    else{
        cout << "Prime Number";
    }
    return 0;
}