#include<iostream>
using namespace std;

#define MAX 100
int size = 0;
int heap[MAX];
void insert(int data) {
    heap[++size] = data;
    int t = size;
    while(t > 1) {
        if(heap[t] > heap[t/2]) {
            swap(heap[t], heap[t/2]);
            t = t/2;
        }
        else return;
    }
    heap[1] = data;
}

void delete_root() {
    if(size == 0) {
        cout << "root is empty!" << endl;
        return;
    }
    cout << endl << heap[1] << " deleted" << endl;

    heap[1] = heap[size];
    size -= 1;
    int t = 1;
    while(t < size) {
        if(heap[t] < heap[2*t]) {
            swap(heap[t], heap[2*t]);
            t = 2*t;
        }
        else if(heap[t] < heap[t*2 + 1]) {
            swap(heap[t], heap[2*t+1]);
            t = 2 * t + 1;
        }
        else return;
    }
}

void print() {
    for(int i = 1; i <= size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    heap[0] = -1;

    int a[10] = {50, 30, 79, 60, 80, 90, 10, 20, 5, 100};
    
    for(int i = 0; i < 10; i++) insert(a[i]);
    
    print();

    delete_root();

    print();
}