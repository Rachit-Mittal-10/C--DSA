// LC 21

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* solve(ListNode* first, ListNode* second){
    // First is always smaller than second for this function.
        ListNode* prev = first;
        ListNode* curr = first->next;
        ListNode* temp = second;
        ListNode* join;

        while(temp!=NULL && curr!=NULL){
            if(temp->val >= prev->val && temp->val <= curr->val){
                join = temp;
                temp = temp->next;
                prev->next = join;
                join->next = curr;
                prev = prev->next;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }

        if(curr == NULL){
            prev->next = temp;
        }

        return first;
    }

public:
    ListNode* mergeTwoLists(ListNode* first, ListNode* second){
        if(first == NULL){
            return second;
        }

        if(second == NULL){
            return first;
        }

        ListNode* head_sorted;

        if(first->val <= second->val){
            head_sorted = solve(first,second);
        }else{
            head_sorted = solve(second,first);
        }

        return head_sorted;
    }
};