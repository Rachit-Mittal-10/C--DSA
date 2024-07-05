#include<bits/stdc++.h>
using namespace std;
// This function returns the reversed string
// Reversal is done with the help of stack
string reverseStrbyStack(string str){
    string answer = "";
    stack<char> stack_ans;
    for(auto i: str){
        stack_ans.push(i);
    }

    while(!stack_ans.empty()){
        answer += stack_ans.top();
        stack_ans.pop();
    }
    return answer;
}

int main(){
    string str = "Rachit";
    cout << str << endl;
    cout << "Function calling" << endl;
    str = reverseStrbyStack(str);
    cout << str << endl;
    return 0;
}