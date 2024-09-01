/*
* LeetCode Question: 20 Valid Paranthesis
todo: We need to check whether the string has valid Paranthesis or not
*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

class solutionStack{
public:
    bool checkParanthesis(string str){
        stack<char> stk;
        for(char c:str){
            if(c == '(' || c == '{' || c == '['){
                stk.push(c);
            }
            else if(!stk.empty() && c == ')' && stk.top() == '('){
                stk.pop();
            }
            else if(!stk.empty() && c == '}' && stk.top() == '{'){
                stk.pop();
            }
            else if(!stk.empty() && c == ']' && stk.top() == '['){
                stk.pop();
            }
            else{
                return false;
            }
        }
        if(stk.empty()){
            return true;
        }
        return false;
    }
};

int main(void){
    string paranthesisString = "}";
    cout << boolalpha << solutionStack().checkParanthesis(paranthesisString) << endl;
}