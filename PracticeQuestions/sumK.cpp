// Question1: https://practice.geeksforgeeks.org/problems/k-sum-paths/1

class Solution1{
    int M = pow(10,9) + 7;
    void solve(Node* root, int k, int& count, vector<int> path){
        if(root == NULL){
            return;
        }
        
        path.push_back(root->data);
        
        solve(root->left,k,count,path);
        solve(root->right,k,count,path);
        
        int size = path.size();
        int sum = 0;
        for(int i=size-1;i>=0;i--){
            sum += path[i];
            if(sum == k){
                count++;
                count = count%M;
            }
        }
        
        path.pop_back();
    }
  public:
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int> path;
        int count = 0;
        solve(root,k,count,path);
        return count;
    }
};


#define mod (int)(1e9+7)

class Solution2{
  public:
    //Recursive utility function to calculate the count of paths with given sum
    void sumK_util(Node *root, int sum, int cur, int &ans, unordered_map<int, int> &mp)
    {
        if(!root)
            return;
        
        //Adding the count of paths with current sum difference in the answer
        ans += mp[cur + root->data - sum];
    
        if(ans >= mod)
            ans %= mod;
        
        //Checking if the current sum is equal to the desired sum, then incrementing answer
        if(cur + root->data == sum)
            ans++;
    
        if(ans >= mod)
            ans %= mod;
        
        //Updating the count of paths with current sum difference
        mp[cur + root->data]++;
    
        if(mp[cur + root->data] >= mod)
            mp[cur + root->data] %= mod;
        
        //Recursive calls for left and right subtree
        sumK_util(root->left, sum, cur+root->data, ans, mp);
        sumK_util(root->right, sum, cur+root->data, ans, mp);
        
        //Backtracking step, decrementing the count of paths with current sum difference
        mp[cur+root->data]--;
    
        if(mp[cur + root->data] <0)
            mp[cur + root->data] += mod;
    }
    
    //Function to calculate the count of paths with given sum
    int sumK(Node *root,int k)
    {
        int ans = 0;
            
        unordered_map<int, int> mp;
            
        sumK_util(root, k, 0, ans, mp);
            
        return ans;
    }
};