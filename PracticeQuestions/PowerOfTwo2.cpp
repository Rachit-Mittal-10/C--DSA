#include<iostream>
using namespace std;
//Power of Two
bool bool_check(int n){
    if(n == 1){
        return true;
    }
    if(n == 0){
        return false;
    }
    int rem = 0;
    while(n!=1){
        rem = n%2;
        if(rem==1){
            return false;
        }
        else{
            n = n/2;
            continue;
        }
    }
    return True;
}

int main(void){
    int n;
    cout << "Enter the N: ";
    cin >> n;
    cout << boolalpha <<bool_check(n) << endl;  // C++ compiler prints 1 for True and 0 for False. To Print We need to set the boolaplha format flag which sets to print in True/Fale.
    return 0;
}