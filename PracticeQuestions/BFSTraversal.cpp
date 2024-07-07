#include<iostream>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> BFSTraversal(unordered_map<int, vector<int>> Graph, int n)
{
    vector<int> result;
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++)
    {

        if (visited[i])
        {
            continue;
        }

        queue<int> order;
        order.push(i);
        while (!order.empty())
        {
            int node = order.front();
            order.pop();
            if (visited[node])
            {
                continue;
            }
            result.push_back(node);
            visited[node] = 1;
            for (auto it : Graph.at(node))
            {
                if (!visited[it])
                {
                    order.push(it);
                }
            }
        }
    }
    return result;
}

int main()
{
    unordered_map<int, vector<int>> Graph;
    Graph[0] = {2, 3};
    Graph[1] = {3, 4};
    Graph[2] = {0, 4};
    Graph[3] = {0, 1};
    Graph[4] = {1, 2};
    Graph[5] = {6, 7};
    Graph[6] = {5};
    Graph[7] = {5};
    vector<int> result = BFSTraversal(Graph, 8);
    for(auto i: result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}