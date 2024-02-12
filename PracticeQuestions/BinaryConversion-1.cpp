// Non Negative Decimal to Binary
#include<math.h>
#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the Non Negative Number: ";
    cin >> n;

    int bin = 0;
    int i = 0;
    // For Binary Representation
    while(n!=0){
        int bit = n&1;  // We check the value of last bit by doing BITWISE AND(&) between 1 and n
        bin += (bit * pow(10,i));
        n = n>>1;   // We rightshift the bit after each operation
        i++;
    }

    int binary[32] = {0};
    i = 31;
    int dig;
    while(bin!=0){
        dig = bin%10;
        binary[i] = dig;
        bin = bin/10;
        i--;
    }
    // Printing the Binary in 32-bit format
    for(int i=0;i<=31;i++){
        cout << binary[i];
    }
    cout << endl;
    return 0;
}