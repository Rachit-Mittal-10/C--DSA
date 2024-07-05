#include<bits/stdc++.h>
using namespace std;

/*
Question Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
*/


// Approach 1: Brute Force. Through Loops
class Approach1{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int size = heights.size();
        int area = 0, l = -1, r = -1, width;
        int max_area = INT_MIN;
        for (int i = 0; i < size; i++)
        {
            l = -1;
            r = -1;
            for (int j = i - 1; j > -1; j--)
            {
                if (heights[j] < heights[i])
                {
                    l = j;
                    break;
                }
            }
            for (int j = i + 1; j < size; j++)
            {
                if (heights[j] < heights[i])
                {
                    r = j;
                    break;
                }
            }
            if (r == -1)
            {
                r = size;
            }
            width = r - l - 1;
            area = heights[i] * width;
            if (area > max_area)
            {
                max_area = area;
            }
        }
        return max_area;
    }
};

// Approach2
// A Bar can be extended till the point it doesn't reach bar smaller than it
// This should give hint of Previous Smaller Element and Next Smaller Element
class Approach2 {
    vector<int> nextSmaller(vector<int>& array){
        stack<int> small;
        small.push(-1);
        int size = array.size();
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
    vector<int> previousSmaller(vector<int>& array){
        stack<int> small;
        small.push(-1);
        int size = array.size();
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
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> leftlimit = previousSmaller(heights);
        vector<int> rightlimit = nextSmaller(heights);
        int size = heights.size();
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
};

int main(void){
    vector<int> heights;
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);
    Approach1 A1;
    cout << A1.largestRectangleArea(heights) << endl;
    return 0;
}