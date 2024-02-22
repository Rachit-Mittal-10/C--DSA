#include<bits/stdc++.h>
using namespace std;

class compare{
    public:
        bool operator()(pair<int,int> a, pair<int,int> b){
            return (a.second > b.second);
        }
};

class Graph{
    unordered_map<int,vector<pair<int,int>>> adjList;
public:
    // If Directed then u to v. directed = true
    // If Undirected. Doesn't matter. directed = false
    void insert(int u, int v, int d,bool directed = false){
        adjList[u].push_back(make_pair(v,d));
        if(!directed){
            adjList[v].push_back(make_pair(u,d));
        }
    }

    void print_adjList(){
        for(auto it: adjList){
            cout << it.first << ": ";
            for(auto i: it.second){
                cout << "(" <<  i.first << "," << i.second << ") " ;
            }
            cout << endl;
        }
    }
    // Total TC: ElogE
    pair<vector<int>,int> PrimAlgoUtil(){
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> minHeap;
        vector<int> parent(adjList.size()+1,-1);
        vector<bool> mst(adjList.size()+1,false);
        int startNode = 1;
        // Total ElogE
        for(auto it: adjList[startNode]){       // E Times
            minHeap.push(it);       // logE time
        }
        mst[startNode] = true;
        int weight = 0;
        // ElogE + V
        while(!minHeap.empty()){        // E times
            auto i = minHeap.top();
            minHeap.pop();      // logE
            if(mst[i.first]){
                continue;
            }
            mst[i.first] = true;
            parent[i.first] = startNode;
            weight += i.second;
            startNode = i.first;
            for(auto it:adjList[startNode]){
                if(!mst[it.first])
                    minHeap.push(it);
            }
            
        }
        return make_pair(parent,weight);
    }
    void PrimAlgo(){
        auto it = PrimAlgoUtil();
        vector<int> parent = it.first;
        int cost = it.second;
        cout << "Weight of MST using Prim's Algorithm: " << cost << endl;
        map<int,pair<int,int>> result;
        result[1] = make_pair(-1,0);
        // V Times At Max
        for(int i=2;i<parent.size();i++){
            int p = parent[i];
            int d = 0;
            for(auto it:adjList[i]){
                if(it.first == p){
                    d = it.second;
                    break;
                }
            }
            result[i] = make_pair(p,d);
        }
        cout << "Adjacency List representing Minimum Spanning Tree({Parent: (Node, Distance from Parent})" << endl;
        for(auto i:result){
            cout << i.first << ": (" << i.second.first << ", " << i.second.second << ")" << endl;
        }
    }
};
int main(){
    Graph G;
    G.insert(1,2,5);
    G.insert(1,5,4);
    G.insert(2,3,2);
    G.insert(2,5,1);
    G.insert(3,4,3);
    G.insert(4,5,6);
    cout << "Adjacency List representing Graph({Node: List of pair(node,edge distance)})" << endl;
    G.print_adjList();
    G.PrimAlgo();
    return 0;
}