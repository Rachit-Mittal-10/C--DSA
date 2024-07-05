#include<bits/stdc++.h>
using namespace std;

class _Queue_{
    // Array Implementation
    int front;
    int rear;
    int queue[100];
    public:
        _Queue_(){
            front = - 1;
            rear = -1;
        }

        void Enqueue(int input){
            if(front == -1){
                front++;
            }
            if(rear == 99){
                cout << "Queue Full" << endl;
                return;
            }
            rear++;
            queue[rear] = input;
        }

        void Dequeue(){
            if(front == -1 || front > rear){
                cout << "Empty Queue" << endl;
                return;
            }
            int temp = queue[front];
            front++;
            cout <<  temp << endl;;
        }
        void Print(){
            for(int i = front;i <= rear;i++){
                cout << queue[i] << " ";
            }cout << endl;
        }

        void Peek(){
            if(front == -1 || front > rear){
                cout << "Empty Queue" << endl;
                return;
            }
            cout << queue[front] << endl;
        }

        bool IsEmpty(){
            if(front == -1 || front > rear){
                return true;
            }
            return false;
        }
};



int main(){
    _Queue_ Q;
    cout << boolalpha << Q.IsEmpty() << endl;   // outputs true
    Q.Enqueue(5);
    Q.Enqueue(8);
    Q.Enqueue(11);
    Q.Print();  // outputs 5 8 11
    Q.Peek(); // outputs 5
    cout << boolalpha << Q.IsEmpty() << endl;   // outputs false
    Q.Dequeue();    // outputs 5
    Q.Dequeue();    // outputs 8
    Q.Dequeue();    // outputs 11
    Q.Dequeue();    // outputs Empty Queue
    return 0;
}