#include<bits/stdc++.h>
using namespace std;

int Queue[100];
int front = -1, rear = -1;
int _size_ = 100;

void Enqueue(int element){
    if(rear >= _size_ -1){
        cout << "Queue Overflow" << endl;
    }else{
        if(front==-1){
            front = 0;
        }
        rear++;
        Queue[rear] = element;
    }
}

void Dequeue(){
    if((front == -1) || (front > rear)){
        cout << "Queue Underflow" << endl;
    }else{
        cout << "Element: " << Queue[front] << endl;
        front++;
    }
}

void Display(){
    if((front == -1) || (front > rear)){
        cout << "Queue is Empty" << endl;
    }else{
        for(int i=front;i<=rear;i++){
            cout << Queue[i] << " ";
        }
        cout << endl;
    }
}

void Peek(){
    if((front == -1) || (front > rear)){
        cout << "Queue is Empty" << endl;
    }else{
        cout << "Front: " << Queue[front] << endl;
        cout << "Rear: " << Queue[rear] << endl;
    }
}

int main(){
    int element,choice;
    cout << "::::Queue Implementation::::" << endl;
    cout << "1) Enqueue\n2) Dequeue\n3) Peek\n4) Display\n5) Exit" << endl;
    do{
        cout << "Enter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the Element: ";
            cin >> element;
            Enqueue(element);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Peek();
            break;
        case 4:
            Display();
            break;
        case 5:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }while(choice!=5);
    return 0;
}