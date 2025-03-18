/*
todo: Search in 2D Matrix
* Leetcode Question: 74
*/

class Solution1 {
/*
: Flattened Binary Search Approach
- Consider the 2d array as flattened array. then row is mid/colCount and col is mid%colCount.
! TC: O(log(m*n))
*/
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowCount = matrix.size();
        int colCount = matrix[0].size();
        int start = 0;
        int end = rowCount*colCount-1;
        int mid, row, col;
        while(start <= end){
            mid = (end-start)/2 + start;
            row = mid/colCount;
            col = mid%colCount;
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] > target){
                end = mid -1;
            }
            else{
                start = mid + 1;
            }
        }
        return false;
    }
};
/*
: This is the Binary Search too but first find the row and then col.
! TC: O(log m + log n) 
*/
class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowCount = matrix.size();
        int colCount = matrix[0].size();
        int rs = 0;
        int cs = 0;
        int re = rowCount-1;
        int ce = colCount-1;
        int rm = 0;
        int cm = 0;
        while(rs <= re){
            rm = (re-rs)/2 + rs;
            if(target < matrix[rm][cs]){
                re = rm-1;
            }
            else if(target > matrix[rm][ce]){
                rs = rm+1;
            }
            else if(target > matrix[rm][cs] && target < matrix[rm][ce]){
                break;
            }
            else{
                break;
            }
        }
        while(cs <= ce){
            cm = (ce-cs)/2 + cs;
            if(target < matrix[rm][cm]){
                ce = cm -1;
            }
            else if(target > matrix[rm][cm]){
                cs = cm+1;
            }
            else{
                return true;
            }
        }
        return false;

    }
};