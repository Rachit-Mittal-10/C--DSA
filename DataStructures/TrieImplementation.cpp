#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode('$');
    }

    void Insert(string s){
        if(s.length() == 0){
            return;
        }
        TrieNode* temp = root;
        for(char ch: s){
            int position = ch - 'a';
            if(temp->children[position] == NULL){
                TrieNode* newNode = new TrieNode(ch);
                temp->children[position] = newNode;
            }
            temp = temp->children[position];
        }
        temp->isTerminal = true;
        return;
    }

    bool Search(string s){
        TrieNode* temp = root;
        for(char ch:s){
            int position = ch - 'a';
            if(temp->children[position] != NULL){
                temp = temp->children[position];
            }else{
                return false;
            }
        }
        if(temp->isTerminal){
            return true;
        }
        return false;
    }

    void Remove(string s){
        TrieNode* temp = root;
        for(char ch:s){
            int position = ch - 'a';
            if(temp->children[position] == NULL){
                return;
            }else{
                temp = temp->children[position];
            }
        }
        temp->isTerminal = false;
        return;
    }
};

int main(){
    Trie T;
    T.Insert("time");
    T.Insert("tim");
    T.Insert("");
    cout << boolalpha << T.Search("time") << endl;
    cout << boolalpha << T.Search("t") << endl;
    cout << boolalpha << T.Search("tim") << endl;
    T.Remove("tim");
    cout << boolalpha << T.Search("tim") << endl;
    return 0;
}