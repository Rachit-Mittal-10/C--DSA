#include<bits/stdc++.h>
#include<D:\C++\Print.hpp>
using namespace std;

class Heap{
public:
    int arr[100];
    int size = 0;

    Heap(){
        for(int i=0;i<100;i++){
            arr[i] = 0;
        }
    }

    void Insert(int data){
        size += 1;
        int index = size;
        arr[index] = data;
        while(index > 1){
            int parentIndex = index/2;
            int parent = arr[parentIndex];
            if(parent >= data){
                break;
            }else{
                swap(arr[index],arr[parentIndex]);
                index = parentIndex;
            }
        }
        return;
    }

    void Delete(){
        if(size == 0){
            return;
        }
        int index = 1;
        arr[index] = arr[size];
        arr[size] = 0;
        size -= 1;
        int left,right;
        while(index < size){
            left = 2*index;
            right = left + 1;

            if(left < size && arr[index] < arr[left]){
                swap(arr[index],arr[left]);
                index = left;
            }
            else if(right < size && arr[index] < arr[right]){
                swap(arr[index],arr[right]);
                index = right;
            }
            else{
                break;
            }
        }
        return;
    }

    void Print(){
        for(int i=1;i<=size;i++){
            cout << arr[i] << " ";
        }cout << endl;
    }
};

// Recursive Algorithm
void Heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = left + 1;
    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i],arr[largest]);
        Heapify(arr,n,largest);
    }
    return;
}

void HeapSort(int arr[],int n){
    int temp = n;
    while(temp > 1){
        // Step 1
        swap(arr[temp],arr[1]);
        // Step 2
        temp --;
        // Step 3
        Heapify(arr,temp,1);
    }
    return;
}

int main(){
    // Heap h;
    // h.Insert(50);
    // h.Insert(55);
    // h.Insert(53);
    // h.Insert(52);
    // h.Insert(54);
    // h.Print();
    // h.Delete();
    // h.Print();

    // int arr[] = {-1,52,55,53,54,50};
    // int size = sizeof(arr)/sizeof(arr[0]);
    // Print(arr,size);
    // int n = size-1;
    // for(int i = n/2;i>0;i--){
    //     Heapify(arr,n,i);
    // }
    // Print(arr,size);
    
    int arr[] = {-1,80,60,70,45,55,50,65};
    int size = sizeof(arr)/sizeof(arr[0]);
    Print(arr,size);
    int n = size - 1;
    HeapSort(arr,n);
    Print(arr,size);
    return 0;
}