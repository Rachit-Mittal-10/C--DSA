#include<iostream>
#include<math.h>
using namespace std;

int type_conversion(char num){
    int ascii = (int)num;
    if(ascii == 49){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    
    string bin_input;   // string is Class in C++ to store the string variables
    cout << "Enter the Binary Representation: ";
    cin >> bin_input;
    int len = bin_input.size(); //.size() is a function in String Class to know the length of string passed.
    int binary[32] = {0};
    int i = 31;
    int j = len-1;
    while(j!=-1){
        binary[i] = type_conversion(bin_input[j]);
        i--;
        j--;
    }
    long long decimal = 0;

    if(binary[0] == 0){
        for(int i=1;i<32;i++){  // We start with i=1 since i = 0 is our most significant bit which actually signifies whether number is +ve or -ve
            decimal += pow(2,31-i)*binary[i];
        }
    }
    else{
        //Taking 1's Complement
        for(int i=0;i<=31;i++){
            if(binary[i]==1){
                binary[i] = 0;
            }
            else{
                binary[i] = 1;
            }
        }
        // Taking 2's Complement
        for(int i=31;i>=1;i++){
            if(binary[i]==0){
                binary[i] = 1;
                break;
            }
            else{
                binary[i] = 0;
            }
        }
        //Finding Decimal Value
        for(int i=1;i<32;i++){
            decimal += pow(2,31-i)*binary[i];
        }
        decimal = -decimal;
    }
    cout << decimal<< endl;
    return 0;
}