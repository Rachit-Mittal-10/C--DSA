/*
Question Link:: https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

We need to remove Duplicates from Unsorted Linked List

Time Complexity: O(N)
Space Complexity: O(N)
*/


Node *removeDuplicates(Node *head)
{
    // your code goes here
    Node *prev = NULL;
    Node *curr = head;
    Node *delete_node;
    unordered_map<int, bool> check_map;
    while (curr != NULL)
    {
        if (check_map[curr->data])
        {
            delete_node = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete delete_node;
        }
        else
        {
            check_map[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}