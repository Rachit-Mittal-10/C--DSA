#include<iostream>
using namespace std;
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(){
        this->val = 0;
        this->next = NULL;
    }
    ListNode(int x){
        this->val = x;
        this->next = NULL;
    }
    ListNode(int x, ListNode* next){
        this->val = x;
        this->next = next;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head_sorted = NULL;
        if(list1 == NULL && list2 == NULL){
            return NULL;
        }
        if(list1 == NULL && list2!=NULL){
            return list2;
        }
        if(list1 != NULL && list2==NULL){
            return list1;
        }

        if(list1->val <= list2->val){
            head_sorted = list1;
            list1 = list1->next;
        }else{
            head_sorted = list2;
            list2 = list2->next;
        }

        ListNode* temp = head_sorted;
        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }
        if(list1==NULL){
            temp->next = list2;
        }

        if(list2 == NULL){
            temp->next = list1;
        }
        return head_sorted;
    }
};

int main(){
    ListNode* headA;
    ListNode* headB;
    
    ListNode* nodeA3 = new ListNode(4);
    ListNode* nodeA2 = new ListNode(2,nodeA3);
    ListNode* nodeA1 = new ListNode(1,nodeA2);
    
    ListNode* nodeB3 = new ListNode(4);
    ListNode* nodeB2 = new ListNode(3,nodeB3);
    ListNode* nodeB1 = new ListNode(1,nodeB2);
    
    headA = nodeA1;
    headB = nodeB1;
    
    Solution S;
    ListNode* collected_head = S.mergeTwoLists(headA,headB);
    ListNode* temp = collected_head;
    while(temp!=NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }cout << endl;
}