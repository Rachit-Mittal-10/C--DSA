/*
* LeetCode Question: 739 Daily Temperaature
todo: Given the array of temperatures, return the array of number of days you had to wait for warmer days
*/

#include<iostream>
#include<vector>
#include"../Print.hpp"
using namespace std;
/*
? Time Compexity: O(N^2)
* Approach:
- Run the for loop across the temperature array:
    - for each index, look for next index having higher value i.e. warmer temperature

! This is inefficient and complexity can be improved by looking at 
*/
class BruteForceApproach{
    int getNext(vector<int> array, int index){
        for(int i=index+1;i<array.size();i++){
            if(array[i] > array[index]){
                return i;
            }
        }
        return -1;
    }
public:
    vector<int> dailyTemperatures(vector<int> temperatures){
        int n = temperatures.size();
        vector<int> answer(n,0);
        for(int i=0;i<n;i++){
            int nextIndex = getNext(temperatures,i);
            if(nextIndex != -1){
                answer[i] = nextIndex-i;
            }
        }
        return answer;
    }
};

class OptimisedApproach{
public:
    vector<int> dailyTemperatures(vector<int> temperatures){
        int n = temperatures.size();
        vector<int> tempIndices(n,-1);
        vector<int> answer(n,0);
        for(int i=n-2;i>=0;i--){
            if(temperatures[i+1] > temperatures[i]){
                tempIndices[i] = i+1;
                continue;
            }
            int j=i+1;
            while(tempIndices[j]!=-1){
                if(temperatures[tempIndices[j]] > temperatures[i]){
                    tempIndices[i] = tempIndices[j];
                    break;
                }
                j = tempIndices[j];
            }
        }
        for(int i=0;i<n;i++){
            if(tempIndices[i] != -1){
                answer[i] = tempIndices[i]-i;
            }
        }
        return answer;
    }
};

int main(void){
    vector<int> temp = {73,74,75,71,69,72,76,73};
    vector<int> answer = OptimisedApproach().dailyTemperatures(temp);
    Print(answer);
}