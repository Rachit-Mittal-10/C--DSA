/*
Question Link:: https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
Linked List Data Structure had three attributes, integer data, next pointer and random pointer.
We need to clone the given Linked List.

## Approach 1:
A) Clone the part Linked List, data and next pointer.
    Traverse the Linked List. While traversing, create a NewNode with data of original node of given Linked List.
    Build the next connection by keeping track of previous pointer.
B) Random Pointer
    Traverse Again the Linked List together, Original and Cloned. Search for node having same data as of original node.
    Build the Random Connection.

    Time Complexity: O(N^2)
    Space Complexity: O(1)

## Approach 2:
A) Same as Approach 1
B) Random Pointer
    While Traversing, Maintain a Map containing the mapping between newNode and originalNode.
    Build the random connection using the mapped data.

    Time Complexity: O(N)
    Space Complexity: O(N)

## Approach 3:
A) Same as Approach 1
B) For Random Pointer
    Add Clone Node in between the Original Nodes of Linked List
    temp->next = clone
    clone->next = temp_next
    Make the Random connections
    temp->next->arb = temp->arb->next
    Revert changes
*/

// Code of Approach2
Node *copyList2(Node *head){
    Node *temp = head;
    Node *temp2 = NULL;
    Node *head2;
    unordered_map<Node *, Node *> nodal_map;
    // Clone Linked List(Data and Next Pointer)
    while (temp != NULL)
    {
        // Creating newNode everytime encountering a node in Original Linked List.
        Node *newNode = new Node(temp->data);
        if (temp2 == NULL)
        {
            temp2 = newNode;
            head2 = temp2;
        }
        else
        {
            temp2->next = newNode;
            temp2 = temp2->next;
        }
        nodal_map[temp] = newNode;
        temp = temp->next;
    }
    temp = head;
    temp2 = head2;
    // Cloned the Random Pointer in Linked List
    while (temp != NULL && temp2 != NULL)
    {
        temp2->arb = nodal_map[temp->arb];
        temp = temp->next;
        temp2 = temp2->next;
    }
    return head2;
}

// Code for Approach-3
Node *copyList(Node *head){
    // Write your code here
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    Node *temp2 = NULL;
    Node *head2;
    // Step 1
    // Clone the basic structure of Linked List
    while (temp != NULL)
    {
        Node *newNode = new Node(temp->data);
        if (temp2 == NULL)
        {
            temp2 = newNode;
            head2 = temp2;
        }
        else
        {
            temp2->next = newNode;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }

    temp = head;
    temp2 = head2;
    Node *next_temp;
    Node *next_temp2;
    // Step-2
    while (temp != NULL && temp2 != NULL)
    {
        // Link Change
        next_temp = temp->next;
        next_temp2 = temp2->next;
        temp->next = temp2;
        temp2->next = next_temp;
        // Moving Forward
        temp = next_temp;
        temp2 = next_temp2;
    }

    temp = head;
    // Step-3
    // Random Pointer
    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            (temp->next)->arb = temp->arb ? (temp->arb)->next : NULL;
            temp = temp->next;
        }
        temp = temp->next;
    }

    // Step-4
    // Reverting the change
    temp = head;
    temp2 = head2;
    while (temp != NULL && temp2 != NULL && temp->next != NULL && temp2->next != NULL)
    {
        temp->next = temp2->next;
        temp = temp->next;
        temp2->next = temp->next;
        temp2 = temp2->next;
    }
    temp->next = NULL;
    temp2->next = NULL;
    return head2;
}

