/*
Question Link: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
*/

// Aproach 1
// TC: O(N^2)
// SC: O(H)
class Solution {
    int height(Node* root){
        if(root == NULL){
            return 0;
        }
        int h_l = height(root->left);
        int h_r = height(root->right);
        
        int ans = max(h_l,h_r) + 1;
        return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        if(root == NULL){
            return 0;
        }
        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = height(root->left) + height(root->right) + 1;
        int ans = max(op1,max(op2,op3));
        return ans;
    }
};