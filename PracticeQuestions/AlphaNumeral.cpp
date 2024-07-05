// Checks whether character input is Upper Case or Lower Case or Numerical

#include<iostream>
using namespace std;

int main(){
    char user_input;
    cin >> user_input;
    // int ascii = int(user_input);
    int ascii = user_input;

    if(ascii>=65 && ascii<=90){
        cout << "Upper Case" << endl;
    }
    else if(ascii>=97 && ascii<=122){
        cout << "Lower Case" << endl;
    }
    else if(ascii>=48 && ascii <=57){
        cout << "Numerical" << endl;
    }
    else{
        cout << "something else" << endl;
    }
}