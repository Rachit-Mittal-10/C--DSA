// Negative Number in Decimal to Binary
#include<iostream>
#include<cstdlib>
#include<math.h>
using namespace std;

int main(){
    int n;
    cout << "Enter The Negative Number: ";
    cin >> n;

    n = abs(n);
    int bin = 0;
    int j = 0;
    // To Find the Binary Representation of Absolute Value of 'n'
    while(n!=0){
        int bit = n&1;
        bin += bit*pow(10,j);
        n = n>>1;
        j++;
    }
    int dig;
    int binary[32] ={0};
    int i = 0;
    // Saving the Bit in Integer Array of size of 32
    while(bin!=0){
        dig = bin%10;
        binary[31-i] = dig;
        i++;
        bin = bin/10;
    }
    //Taking One's Complement
    for(int i=0;i<=31;i++){
        if(binary[i] == 0){
            binary[i] = 1;
        }
        else{
            binary[i] = 0;
        }
    }
    //Taking Two Complement
    for(i=31;i>=0;i--){
        if(binary[i]==0){
            binary[i] = 1;
            break;
        }
        else{
            binary[i] = 0;
        }
    }

    for(int i=0;i<=31;i++){
        cout << binary[i];
    }
    cout <<endl;
    return 0;
}