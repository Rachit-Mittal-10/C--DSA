/*
Question Link: https://practice.geeksforgeeks.org/problems/max-rectangle/1
Use the Logic of Largest Histogram.

Calculate Area row-wise. First Area of Row-1. Then add Row-1 to Row-2. Calculate the Area of updated Row-2. Compare it with previous max_area.
Proceed similarly. 
Note: When M[][] = 0, then don't add previous row value.
*/

class Solution{
        vector<int> nextSmaller(int* array,int size){
        stack<int> small;
        small.push(-1);
        vector<int> answer(size);
        for(int i=size-1;i>-1;i--){
            int curr = array[i];
            while(array[small.top()]>=curr && small.top()!=-1){
                small.pop();
            }
            answer[i] = small.top();
            small.push(i);
        }
        return answer;
    }
    vector<int> previousSmaller(int* array, int size){
        stack<int> small;
        small.push(-1);
        vector<int> answer(size);
        for(int i=0;i<size;i++){
            int curr = array[i];
            while(array[small.top()]>=curr && small.top()!=-1){
                small.pop();
            }
            answer[i] = small.top();
            small.push(i);
        }
        return answer; 
    }
    int largestRectangleArea(int* heights, int size) {
        vector<int> leftlimit = previousSmaller(heights,size);
        vector<int> rightlimit = nextSmaller(heights,size);
        int area = 0;
        int max_area = INT_MIN;
        int width = 0;
        for(int i=0;i<size;i++){
            width = (rightlimit[i]!=-1 ? rightlimit[i] : size) - leftlimit[i]-1;
            area = heights[i]*width;
            if(area>max_area){
                max_area = area;
            }
        }
        return max_area;
    }
public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int max_area = largestRectangleArea(M[0],m);
        int area = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                // Update Row
                if(M[i][j] !=0){
                    M[i][j] += M[i-1][j];
                }
            }
            area = largestRectangleArea(M[i],m);
            max_area = max(max_area,area);
        }
        return max_area;
    }
};