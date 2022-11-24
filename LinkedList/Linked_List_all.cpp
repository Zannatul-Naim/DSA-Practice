#include<iostream>
using namespace std;

struct Node {  // Node
    int data;
    Node *next;
};

typedef Node node;
node* head = NULL;

node* createNode(int data) {  // create node 
    node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void create_list(int a[], int size) {  // create the list
    for(int i = 0; i < size; i++) {
        if(head == NULL) head = createNode(a[i]);
        else {
            node *temp = head;
            while(temp -> next != NULL) temp = temp->next;
            temp->next = createNode(a[i]);
        }
    }
}

void traverse() {  // traverse the entire linked list

    node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insert_at_pos(int pos, int data) {  // insert at specific position
    
    int i = 1;
    if(pos == 1 || head == NULL) {
        node *temp = createNode(data);
        temp->next = head;
        head = temp;
        return;
    }

    node *temp1, *temp2;

    temp1 = head;
    temp2 = temp1;
    while(i < pos) {
        temp2 = temp1;
        temp1 = temp1->next;
        i++;
    }
    node *temp = createNode(data);
    temp2 -> next = temp;
    temp -> next = temp1;

}

void delete_first() {  // delete first value
    
    if(head == NULL) {
        cout << "Nothing to delete!" << endl;
        return;
    }

    node *temp = head;
    head = head->next;
}

void delete_last() { // Delete the last value

    if(head == NULL) {
        cout << "Empty List!" << endl;
        return;
    }

    node *temp = head;
    node *temp1 = temp;
    while(temp -> next != NULL) {
        temp1 = temp;
        temp = temp -> next;
    }
    temp1 -> next = NULL;
    free(temp);
}

void delete_at_pos(int pos) {  // delete from the specific position from the linked list
    
    int i = 1;
    if(head == NULL) return;
    if(pos == 1) {
        head == head->next;
        return;
    }
    node *curr, *prev;
    curr = head;
    prev = curr;
    while(i < pos) {
        prev = curr;
        curr = curr->next;
        i++;
    }

    prev->next = curr->next;

}

void sort() {  // sort the entire linked list

    if(head == NULL) cout << "Empty list!" << endl;

    node *temp = head;

    while(temp != NULL) {
        node *stemp = temp->next;
        while(stemp != NULL) {
            if(temp->data > stemp->data) {
                int t = temp->data;
                temp->data = stemp->data;
                stemp->data = t;
            }
            stemp = stemp->next;
        }
        temp = temp->next;
    }
}

int search(int data) {  // Search for specific data into linked list
    
    node *temp = head;
    int pos = 0;

    if(head == NULL) {
        cout << "Empty List" << endl;
        return -1;
    }

    while(temp != NULL) {
        pos++;
        if(temp->data == data) return pos;
        temp = temp->next;
    }
    return -1;
}

int main() {

    int a[11] = {5, 3, 9, 42, 0, 10, 15, 36, 8, 12, 1};

    create_list(a, 11);
    traverse();

    insert_at_pos(1, 50);
    traverse();

    insert_at_pos(5, 100);
    traverse();

    delete_first();
    traverse();

    delete_last();
    traverse();

    delete_at_pos(6);
    traverse();

    sort();
    cout << "After sorting : ";
    traverse();

    int pos = search(15);
    if(pos == -1) cout << "Not found!" << endl;
    else cout << "Search for " << 15 << " Found at position : " << pos << endl;

    pos = search(19);
    if(pos == -1) cout << "Not found!" << endl;
    else cout << "Search for " << 15 << " Found at position : " << pos << endl;

    return 0;
}