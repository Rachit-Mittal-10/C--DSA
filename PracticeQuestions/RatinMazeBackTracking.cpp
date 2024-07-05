// Question Link: https://www.codingninjas.com/studio/problems/rat-in-a-maze_1215030

#include <bits/stdc++.h>
bool isSafe(int x, int y, int n, vector<vector<int>>& arr,vector<vector<bool>>& visit){
    if(x >=0 && x < n && y>=0 && y<n && visit[x][y] != true && arr[x][y] == 1){
        return true;
    }
    return false;
}
void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string>& ans,vector<vector<bool>>& visit, string path){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    visit[x][y] = true;
    // Down
    if(isSafe(x+1,y,n,arr,visit)){
        path.push_back('D');
        solve(x+1, y, arr, n, ans, visit, path);
        path.pop_back();
    }
    // Left
    if(isSafe(x,y-1,n,arr,visit)){
        path.push_back('L');
        solve(x, y-1, arr, n, ans, visit, path);
        path.pop_back();
    }
    // Right
    if(isSafe(x,y+1,n,arr,visit)){
        path.push_back('R');
        solve(x, y+1, arr, n, ans, visit, path);
        path.pop_back();
    }
    // Up
    if(isSafe(x-1,y,n,arr,visit)){
        path.push_back('U');
        solve(x-1, y, arr, n, ans, visit, path);
        path.pop_back();
    }
    visit[x][y] = false;
    return;
} 
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> answer;
    vector<vector<bool>> visit(n, vector<bool>(n,false));
    string path = "";
    if(arr[0][0] == 0){
        return answer;
    }
    solve(0,0,arr,n,answer,visit,path);
    return answer;
}