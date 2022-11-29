#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

};


typedef Node node;

node *start = NULL;

void printList() {
    node *temp = start;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insert(int data) {
    if(start == NULL) {
        start = new Node(data);
        printList();
        return;
    }

    if(start->data > data) {
        node *temp = new Node(data);
        temp->next = start;
        start = temp;
        printList();
        return;
    }
    node *temp = start;
    node *prev = temp;    
    while(temp != NULL) {
        if(temp->data <= data) {
            prev = temp;
            temp = temp->next;
        }
        else break;
    }

    prev->next = new Node(data);
    prev->next->next = temp;

    printList();
}

int main() {

    int a[5] = {5,4,6,7,3};
    for(int i = 0; i < 5; i++) {
        insert(a[i]);
    }

    cout << endl;
    printList();

    return 0;
}
