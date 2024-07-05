#include<iostream>
using namespace std;
// Simple Calculator Program
int main(){
    int num1=0,num2=0;
    char operator_;

    cout << "Enter the Number 1: ";
    cin >> num1;
    
    cout << "Enter the Number 2: ";
    cin >> num2;
    
    cout << "Enter the Operator: ";
    cin >> operator_;

    switch(operator_){
        case '+':{
            cout << num1 + num2<<endl;
            break;
        }
        case '-':{
            cout << num1-num2<<endl;
            break;
        }
        case '/':{
            cout << num1/num2 << endl;
            break;
        }
        case '*':{
            cout << num1*num2 << endl;
            break;
        }
        case '%':{
            cout << num1%num2 << endl;
        }
        default:{
            cout << "No Operator specified" << endl;
        }
    }
    return 0;
}