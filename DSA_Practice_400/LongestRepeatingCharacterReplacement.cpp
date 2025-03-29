#include<bits/stdc++.h>
using namespace std;

/* 
todo: find the longest substring after replacing k character
*/


class Solution1{
/* 
: Two Pointer and Sliding Window Approach
- Initiaise the left and right pointer as start of aray and initlise the varible to keep track of max frequency
- initliase the hash map also
- start traversing from start to end of string
    - insert the current element to map mp[s[right]]++ and see if any change is required.
    - if change required is less than k move right pointer:
        - if not move further. update the max len
    - if change required is greater than k then move the left point and update the map too. mp[s[left]]--; cross check the max frequency at this step.
    - update max frequency at every iteration

! Time Complexity: O(27N)
! Space Complexity: O(1)

*/
public:

    int solve(string s, int k){
        int left = 0;
        int right = 0;
        int MAX_LEN = INT_MIN;
        int MAX_FREQUENCY = 0;
        vector<int> hashArray(26,0);
        int n = s.size();
        while(right < n && left < n){
            hashArray[s[right]-'A']++;
            MAX_FREQUENCY = max(MAX_FREQUENCY, hashArray[s[right]-'A']);
            while((r-l+1) - MAX_FREQUENCY > k){
                hashArray[s[left]-'A']--;
                MAX_FREQUENCY = hashArray[0];
                for(auto i:hashArray){
                    MAX_FREQUENCY = max(i,MAX_FREQUENCY);
                }
                left++;
            }
            if(r-l+1 - MAX_FREQUENCY <= k){
                MAX_LEN = max(MAX_LEN,r-l+1);
            }
            right++;
        }
        return MAX_LEN;
    }
};

int main(void){
    
    return 0;
}