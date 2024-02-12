#include<bits/stdc++.h>
using namespace std;

/*
Spell the Number
Ex 423 = Four Two Three
403 = Four Zero Three
Limitation: Cannot Spell '0'
0 = Zero    Not Possible
*/
vector<string> spell_vector{"Zero","One", "Two", "Three","Four","Five","Six","Seven","Eight", "Nine"};

void Spell(int n){
    if(n < 0) return;
    if(n == 0){
        return;
    }
    int dig = n%10;
    n = n/10;
    Spell(n);
    cout << spell_vector[dig] << " ";
}

int main(){
    int n;
    cin >> n;
    Spell(n);
    cout << endl;
    return 0;
}