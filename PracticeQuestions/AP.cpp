#include<iostream>
using namespace std;

// Nth term of Arithmetic Progression

int AP(int n){
    int term = 3 * n + 7;
    return term;
}
int main(){
    int num;
    cout << "Enter the Number, N: ";
    cin >> num;
    cout << "Nth Term: " << AP(num) << endl;
    return 0;
}