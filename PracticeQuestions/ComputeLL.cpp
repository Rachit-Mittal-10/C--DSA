/*
Question Link:: https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1
*/

class Solution
{   
    private:
    Node* Reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        
        int MAX = INT_MIN;
        head = Reverse(head);
        Node* temp = head;
        Node* prev = NULL;
        Node* temp_del = NULL;
        while(temp!=NULL){
            if(temp->data >= MAX){
                MAX = temp->data;
                prev = temp;
                temp = temp->next;
            }else{
                temp_del = temp;
                prev->next = temp->next;
                temp = temp->next;
                delete temp_del;
            }
        }
        head = Reverse(head);
        return head;
    }
    
};