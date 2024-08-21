/*
* LeetCode Question: 567 Permutation in string
@param strings, s1 and s2

todo: Here we need to return true if the permutation of s1 appears in s2 or in otherwords, s2 contains permutation of s1.
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;


class BruteForceSolution{
    vector<string> getPermutation(string s){
        vector<string> answer;
        sort(s.begin(),s.end());
        do{
            answer.push_back(s);
        }while(next_permutation(s.begin(),s.end()));
        return answer;
    }
public:
    bool checkInclusion(string s1, string s2){
        if(s1.size()>s2.size()){
            return false;
        }
        vector<string> permutationS1 = getPermutation(s1);
        for(string str: permutationS1){
            if(s2.find(str) != string::npos){
                return true;
            }
        }
        return false;
    }
};

int main(void){
    string s1 = "ab";
    string s2 = "eidboaooo";
    cout << boolalpha << BruteForceSolution().checkInclusion(s1,s2) << endl;
}