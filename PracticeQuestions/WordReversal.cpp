#include <iostream>
#include<cctype>
#include<vector>
#include<string>
using namespace std;


// REVERSAL OF WORDS IN A SENTENCE

vector<string> Wording(string S){
    vector<string> word;
    int start = 0;
    int end = 0;
    for(int i = 0;i<=S.size();i++){
        if(isspace(S[i])||S[i]=='\0'){
            end = i ;
            word.push_back(S.substr(start,end));
            start = i + 1;
        }
    }
    
    return word;
}

string reverse(string s){
    int start = 0;
    int end = s.size()-1;

    while(start<=end){
        swap(s[start],s[end]);
        start++;
        end--;
    }
    return s;
}

int main(){
    
    vector<string> word;
    string S = "Rachit Mittal";
    word = Wording(S);
    string reversed = "";
    for(string s:word){
        reversed += (" " + reverse(s)); 
    }

    cout << reversed << endl;
    return 0;
}
