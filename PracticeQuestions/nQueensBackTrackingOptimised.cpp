// row -> T/F
unordered_map<int,bool> rowCheck;
// row-col -> T/F
unordered_map<int,bool> UpperLeftDiagonalCheck;
// row+col ->T/F
unordered_map<int,bool> BottomLeftDiagonalCheck;

// TC: O(N^2)
void addSolution(vector<vector<int>>& ans, vector<vector<int>>& board, int n){
	vector<int> temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}

// TC: O(N)
bool isSafe(int row, int col, vector<vector<int>>& board, int n){

	if(!rowCheck[row] && !UpperLeftDiagonalCheck[row-col] && !BottomLeftDiagonalCheck[row+col]){
		return true;
	}
	return false;
}

// TC: O(N^3)
void solve(int col,vector<vector<int>>& board,vector<vector<int>>&ans,int n){
	if(col == n){
		addSolution(ans, board, n);
		return;
	}

	for(int row=0;row<n;row++){
		if(isSafe(row,col,board,n)){
			rowCheck[row] = true;
			UpperLeftDiagonalCheck[row-col] = true;
			BottomLeftDiagonalCheck[row+col] = true;
			board[row][col] = 1;

			// Recursive Step
			solve(col+1,board,ans,n);
			
			// Back Track
			board[row][col] = 0;
			rowCheck[row] = false;
			UpperLeftDiagonalCheck[row-col] = false;
			BottomLeftDiagonalCheck[row+col] = false;
		}
	}
}

vector<vector<int>> nQueens(int n){
	// Write your code here
	vector<vector<int>> board(n,vector<int>(n,0));
	vector<vector<int>> ans;
	solve(0,board,ans,n);
	return ans;
	
}