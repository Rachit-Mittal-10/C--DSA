// Question link: https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/14

// Morris Travel
class Solution1{
public:
    void flatten(Node *root){
        Node* curr = root;
        Node* prev = NULL;
        while(curr){
            if(curr->left){
                prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

// Recursive Approach
class Solution2{
public:
    void flatten_recursive(Node* root){
        if(root == NULL){
            return;
        }
        flatten(root->left);
        flatten(root->right);

        Node* temp = root->right;

        if(root->left){
            root->right = root->left;
            root->left = NULL;
            Node* curr = root->right;
            while(curr->right){
                curr = curr->right;
            }
            curr->right = temp;
        }
    }
};