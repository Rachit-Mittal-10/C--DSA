#include<bits/stdc++.h>
using namespace std;

void Reverse(string& S, int Start, int End){
    if(Start > End) return;

    swap(S[Start],S[End]);
    Start++;
    End--;
    Reverse(S,Start,End);
}

int main(){
    string Actual = "ABCDEF";
    int s = 0;
    int e = Actual.length()-1;
    cout << Actual << endl;
    Reverse(Actual,s,e);
    cout << Actual << endl;
    return 0;
}