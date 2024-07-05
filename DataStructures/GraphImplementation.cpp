#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T,vector<T>> adjList;
public:
    // If Directed then u to v. directed = true
    // If Undirected. Doesn't matter. directed = false
    void insert(T u, T v, bool directed = false){
        adjList[u].push_back(v);
        if(!directed){
            adjList[v].push_back(u);
        }
    }

    void print_adjList(){
        for(auto it: adjList){
            cout << it.first << ": ";
            for(auto i: it.second){
                cout << i << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph<int> G1;
    G1.insert(0,1,true);
    G1.insert(0,6);
    G1.insert(1,2);
    G1.insert(1,4,true);
    G1.insert(3,2);
    G1.insert(3,5);
    G1.insert(4,2);
    G1.insert(5,0);
    G1.insert(6,2,true);

    G1.print_adjList();
    return 0;
}