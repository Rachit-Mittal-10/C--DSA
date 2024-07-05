#include<iostream>
using namespace std;
// Finding the number of denomination required for particular amount
int main(){
    int amount = 0;
    cout << "Enter the Amount: ";
    cin >> amount;
    int hundred=0, fifty=0,twenty=0,ten=0;
    int denomination[] = {100,50,20,10};
    int i = 0;
    while(amount!=0&&i<=3){
        
        switch(denomination[i]){
            case 100:{
                hundred = amount/100;
                break;
            }
            case 50:{
                fifty = amount/50;
                break;
            }
            case 20: {
                twenty = amount/20;
                break;
            }
            case 10:{
                ten = amount/10;
                break;
            }
        }
        
        amount = amount%denomination[i];
        i++;
    }
    cout << "Amount of Hundred Notes: " << hundred<<endl;
    cout << "Amount of Fifty Notes: " << fifty<<endl;
    cout << "Amount of Twenty Notes: " << twenty<<endl;
    cout << "Amount of Ten Notes: " << ten<<endl;
    return 0;
}