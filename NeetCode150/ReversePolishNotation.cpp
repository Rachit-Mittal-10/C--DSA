/*
* LeetCode Question: 150 Reverse Polish Notation Evaluate
todo: Evaluate the Reverse Polish Notation

@params: array of tokens
*/

#include<stack>
#include<iostream>
#include<vector>
using namespace std;

class Approach1{
    int getAnswer(int num1, int num2, string token){
        if(token  == "+"){
            return num2+num1;
        }
        else if(token == "-"){
            return num2-num1;
        }
        else if(token == "*"){
            return num2*num1;
        }
        else if(token == "/"){
            return num2/num1;
        }
        return -1;
    }
public:
    int evaluateReversePolishNotation(vector<string> tokens){
        stack<string> Stk;
        for(string token: tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int num1 = stoi(Stk.top());
                Stk.pop();
                int num2 = stoi(Stk.top());
                Stk.pop();
                int answer = getAnswer(num1,num2,token);
                Stk.push(to_string(answer));
                continue;
            }
            Stk.push(token);
        }
        return stoi(Stk.top());
    }
};

int main(void){
    vector<string> tokens = {"4","3","-"};
    cout << Approach1().evaluateReversePolishNotation(tokens) << endl;
}