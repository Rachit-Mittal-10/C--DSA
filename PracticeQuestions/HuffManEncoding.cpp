    #include<bits/stdc++.h>
    using namespace std;

    class node{
    public:
        char data;
        int frequency;
        node* left, *right;
        string code;
        bool isLeaf;
        node(char ch, int f){
            this->data = ch;
            this->frequency = f;
            this->left = this->right = nullptr;
            if(ch == '$'){
                this->isLeaf = false;
            }else{
                this->isLeaf = true;
            }
        }
    };

    class compare{
    public:
        bool operator()(node* a, node* b){
            return (a->frequency > b->frequency);
        }
    };

    node* BuildHuffmanTree(vector<node*> arr){
        priority_queue<node*, vector<node*>, compare> minHeap;
        int size_arr = arr.size();
        for(int i=0;i<size_arr;i++){
            minHeap.push(arr[i]);
        }
        while(minHeap.size()>1){
            node* left = minHeap.top();
            minHeap.pop();
            node* right = minHeap.top();
            minHeap.pop();
            int newFreq = left->frequency + right->frequency;
            node* newNode = new node('$',newFreq);
            newNode->left = left;
            newNode->right = right;
            minHeap.push(newNode);
        }
        return minHeap.top();
    }

    void HuffmanCodesUtil(node* root, string code){
        if(root->left){
            root->left->code = code + '0';
            HuffmanCodesUtil(root->left, root->left->code);
        }
        if(root->right){
            root->right->code = code + '1';
            HuffmanCodesUtil( root->right, root->right->code);
        }
    }

    void HuffmanCodes(node*root){
        string temp = "";
        HuffmanCodesUtil(root,temp);
    }

    int main(){
        node *n1, *n2, *n3, *n4,*n5,*n6;
        n1 = new node('m',1);
        n2 = new node('i',4);
        n3 = new node('s',4);
        n4 = new node('p',2);
        vector<node*> arr = {n1,n2,n3,n4};
        node* r1 = BuildHuffmanTree(arr);
        HuffmanCodes(r1);
        for(auto i:arr){
            cout << i->data << " " << i->code << endl;
        }
        return 0;
    }