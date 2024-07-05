#include<iostream>
using namespace std;

/*
Setbits:- Bit whose value is '1' in Binary Representation
*/
// Counting the set bits in a number
int count_setbits(int num){
    int ctr = 0;
    while(num!=0){
        if(num&1==1){
            ctr++;
        }
        num = num >>1;
    }

    return ctr;
}
// Program find the total number of setbits in two integer
int main(){
    int a,b,total_setbits;
    cin >> a >> b;
    total_setbits = count_setbits(a) + count_setbits(b);
    cout << total_setbits << endl;
    return 0;
}