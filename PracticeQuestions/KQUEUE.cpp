/*
Implement K Queues in Single Array
*/

#include<bits/stdc++.h>
using namespace std;

class kQueue{
    int n,k,freespot;
    int *rear, *front, *arr, *next;
public:
    kQueue(int n,int k){
        this->n = n;
        this->k = k;
        rear = new int[k];
        front = new int[k];
        next = new int[n];
        arr = new int[n];
        freespot = 0;
        for(int i=0;i<k;i++){
            rear[i] = -1;
            front[i] = -1;
        }
        for(int i=0;i<n;i++){
            next[i] = i+1;
            arr[i] = -1;
        }
        next[n-1] = -1;
    }

    void enqueue(int data, int position){
        if(freespot == -1){
            cout << "NO FREESPACE PRESENT" << endl;
            return;
        }
        // Find Index of data insertion
        int index = freespot;
        // Update Freespot
        freespot = next[index];
        // Check for First Element and update front/next of rear
        if(front[position-1] == -1){
            front[position-1] = index;
        }else{
            // Link New element to previous element
            next[rear[position-1]] = index;
        }
        // Update Next of index
        next[index] = -1;
        // Update rear
        rear[position-1] = index;
        // Insert Data
        arr[index] = data;
    }

    void dequeue(int position){
        if(front[position-1] == -1){
            cout << "Underflow" << endl;
            return;
        }
        // Find Index
        int index = front[position-1];
        // Update Front
        front[position-1] = next[index];
        // Update Next
        next[index] = freespot;
        // Update Freespot
        freespot = index;
    }
};

int main(){
    kQueue *obj = new kQueue(9,3);
    obj->enqueue(5,1);
    obj->enqueue(10,2);
    obj->enqueue(6,3);
    obj->enqueue(15,1);
    obj->dequeue(1);
    return 0;
}