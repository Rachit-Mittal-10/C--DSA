#include<iostream>
using namespace std;

// We Used the Bits to check whether a number is Even or Odd.
// If It is Even, then It would 0 in his last bit. For odd, It would be 1.
// EX: 7 = 111      All of these had 1 in their las bit
// 5 = 101      All of these had 1 in their las bit
// 3 = 11       All of these had 1 in their las bit
// 2 = 10       All of these had 0 in their last bit
// 4 = 100      All of these had 0 in their last bit
// 6 = 110      All of these had 0 in their last bit
bool Is_Even(int num){
    if((num&1)==0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int num;
    cout << "Enter the Number: ";
    cin >> num;
    if(Is_Even(num)){
        cout << "Even";
    }
    else{
        cout << "Odd";
    }
    return 0;
}