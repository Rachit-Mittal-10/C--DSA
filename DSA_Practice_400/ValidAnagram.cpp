#include<bits/stdc++.h>
using namespace std;

class BruteForceSolution{
    
public:
    bool validAnagram(string s1, string s2){
            vector<int> hashArr1(26,0);
            for(auto c:s1){
                if(!isalpha(c)){
                    continue;
                }
                hashArr1[c-'a']++;
            }
            for(auto c:s2){
                if(!isalpha(c)){
                    continue;
                }
                hashArr1[c-'a']--;
            }
            for(auto i:hashArr1){
                if(i != 0){
                    return false;
                }
            }
            return true;
    }
};

int main(void){
    auto S =BruteForceSolution();
    cout << boolalpha << S.validAnagram("anagram","nagaam") << endl;
    return 0;
}