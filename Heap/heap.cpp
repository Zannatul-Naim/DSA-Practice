#include<iostream>
using namespace std;

#define MAX_SIZE 100

class Heap {
    public:
        int heap[MAX_SIZE];
        int size;

        Heap() {
            heap[0] = -1;
            size = 0;
        }
    
    void insert(int data) {
        size += 1;
        int temp_index = size;
        heap[size] = data;

        while(temp_index > 1) {
            if(heap[temp_index] > heap[temp_index/2]) {
                swap(heap[temp_index], heap[temp_index/2]);
                temp_index = temp_index/2;
            }
            else return;
        }

        heap[1] = data;  // data is root or greater than root
    }

    void display() {
        cout << "Heap is : ";
        for(int i = 1; i <= size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void delete_root() {
        if(size == 0) {
            cout << "Empty heap!" << endl;
            return;
        } 
        cout << "Deleted : " << heap[1] << endl;

        heap[1] = heap[size];
        size -= 1;
        int temp_index = 1;
        while(temp_index < size) {
            if(heap[temp_index] < heap[temp_index*2]) {
                swap(heap[temp_index], heap[temp_index*2]);
                temp_index = temp_index*2;
            }
            else if(heap[temp_index] < heap[temp_index*2 + 1]) {
                swap(heap[temp_index], heap[temp_index*2 + 1]);
                temp_index = temp_index*2 + 1;
            }
            else return;
        }
    }
};


int main() {
    Heap heap;
    for(int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        heap.insert(x);
    }

    heap.display();
    
    heap.delete_root();
    heap.display();

    return 0;
}