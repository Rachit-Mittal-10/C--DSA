#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void inorder(TreeNode* root, vector<TreeNode*>& in);
void inorder(TreeNode* root, vector<int>& in);
TreeNode* flatten(TreeNode* root);
TreeNode* Merge(TreeNode* root1, TreeNode* root2);
int countNodes(TreeNode* root);
static TreeNode* LLtoBST(TreeNode** head, int n);
vector<int> mergeBST(TreeNode *root1, TreeNode *root2);

int main(){
    TreeNode *r1,*r2, *n11,*n12,*n13,*n21;
    n12 = new TreeNode(1);
    n13 = new TreeNode(3);
    n11 = new TreeNode(2,n12,n13);
    r1 = n11;
    n21 = new TreeNode(4);
    r2 = n21;
    vector<int> in;
    in = mergeBST(r1,r2);
    return 0;
}

void inorder(TreeNode* root, vector<TreeNode*>& in){
    if(root == NULL){
        return;
    }

    inorder(root->left, in);
    in.push_back(root);
    inorder(root->right,in);
    return;
}

void inorder(TreeNode* root, vector<int>& in){
    if(root == NULL){
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right,in);
    return;
}

TreeNode* flatten(TreeNode* root){
    if(root == NULL){
        return NULL;
    }
    vector<TreeNode*> in;
    inorder(root,in);
    int n = in.size()-1;
    if(n==0){
        return in[0];
    }
    TreeNode *curr = NULL,*next = NULL;
    for(int i=0;i<n;i++){
        curr = in[i];
        next = in[i+1];
        curr->left = NULL;
        curr->right = next;
    }
    next->left = NULL;
    next->right = NULL;
    return in[0];
}

TreeNode* Merge(TreeNode* root1, TreeNode* root2){
    if(root1 == NULL && root2 == NULL){
        return NULL;
    }
    if(root1 == NULL && root2 != NULL){
        return root2;
    }
    if(root1 != NULL && root2 == NULL){
        return root1;
    }
    TreeNode* dummy, *root;
    dummy = new TreeNode(-1);
    root = dummy;
    while(root1 && root2){
        if(root1->data <= root2->data){
            dummy->right = root1;
            root1 = root1->right;
        }else{
            dummy->right = root2;
            root2 = root2->right;
        }
        dummy = dummy->right;
    }
    if(root1){
        dummy->right = root1;
    }
    if(root2){
        dummy->right = root2;
    }
    dummy = root;
    root = root->right;
    delete dummy;
    return root;
}

int countNodes(TreeNode* root){
    int cnt = 0;
    while(root){
        cnt++;
        root = root->right;
    }
    return cnt;
}

static TreeNode* LLtoBST(TreeNode** head, int n){
    if(n<=0){
        return NULL;
    }

    TreeNode* left = LLtoBST(head,n/2);

    TreeNode* root = new TreeNode((*head)->data);
    root->left = *head;
    *head = (*head)->right;

    TreeNode* right = LLtoBST(head, n - n/2 - 1);

    root->right = right;

    return root;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2){
    // Write your code here.
    if(root1 == NULL && root2 == NULL){
        return vector<int>();
    }
    if(root1 == NULL && root2 != NULL){
        vector<int> in;
        inorder(root2, in);
        return in;
    }
    if(root1 != NULL && root2 == NULL){
        vector<int> in;
        inorder(root1, in);
        return in;
    }
    root1 = flatten(root1);
    root2 = flatten(root2);
    TreeNode* root = Merge(root1,root2);
    root = LLtoBST(&root, countNodes(root));
    vector<int> in = {0};
    inorder(root, in);
    return in;
}