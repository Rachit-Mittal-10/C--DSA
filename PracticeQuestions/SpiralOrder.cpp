#include<bits/stdc++.h>
using namespace std;

void Print(vector<vector<int>> vect);
void Print(vector<int> vect);
vector<int> spiralOrder(vector<vector<int>>& matrix);

int main(){
    vector<vector<int>> vect{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    Print(vect);
    vector<int> answer = spiralOrder(vect);
    Print(answer);
    return 0;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int StartR = 0;
    int StartC = 0;
    int EndR = rows-1;
    int EndC = cols-1;
    int total = rows * cols;
    int count = 0;
    vector<int> answer;
    while(count < total){
        // Starting Row
        for(int i = StartC;count < total && i<=EndC;i++){
            answer.push_back(matrix[StartR][i]);
            count++;
        }
        StartR++;
        // Ending Column
        for(int i = StartR;count < total && i<=EndR;i++){
            answer.push_back(matrix[i][EndC]);
            count++;
        }
        EndC--;
        // Ending Row
        for(int i = EndC;count < total && i>=StartC;i--){
            answer.push_back(matrix[EndR][i]);
            count++;
        }
        EndR--;
        // Starting Column
        for(int i = EndR;count < total && i>=StartR;i--){
            answer.push_back(matrix[i][StartC]);
            count++;
        }
        StartC++;
    }
    return answer;
}


void Print(vector<vector<int>> vect){
    int row = vect.size();
    int col = vect[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
}

void Print(vector<int> vect){
    int n = vect.size();
    for(int i=0;i<n;i++){
        cout << vect[i] << " ";
    }cout << endl;
}