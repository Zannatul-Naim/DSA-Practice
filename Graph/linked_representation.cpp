#include<iostream>

using namespace std;


class Node {
    public:
    int data;
    int status;
    Node *next;
    class Adjacent *adjacent;

    Node(int data) {
        this->data = data;
        this->status = 0;
        this->next = NULL;
        this->adjacent = NULL;
    }
};

class Adjacent {
    public:
    class Node *node;
    Adjacent *next;
    Adjacent(Node *node) {
        this->node = node;
        this->next = NULL;
    }
};

typedef Node node;
typedef Adjacent adjcent;

node *start = NULL, *nodeptr;
adjcent *adjacentptr = NULL;

void createNodeList(int v) {
    node *tail = start;
    for(int i = 0; i < v; i++) {
        if(i == 0) {
            start = new Node(i);
            tail = start;
        }
        else {
            tail->next = new Node(i);
            tail = tail->next;
        }
    }
}

void printNodeList() {
    node *temp = start;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node* findNodeForItem(int item) {
    node *temp = start;
    while(temp != NULL) {
        if(temp->data == item) return temp;
        temp = temp->next;
    }
    return NULL;
}

void createGraph() {
    cout << "Enter number of vertexes : ";
    int vertex;
    cin >> vertex;
    createNodeList(vertex);
    printNodeList();

    nodeptr = start;
    while(nodeptr != NULL) {
        adjacentptr = NULL;
        cout << "Enter connected nodes with " << nodeptr->data << " (-1) for end : ";
        while(true) {
            int item;
            cin >> item;
            if(item == -1) break;
            else if(findNodeForItem(item) != NULL) {
                node *temp = findNodeForItem(item);
                if(nodeptr->adjacent == NULL) {
                    nodeptr->adjacent = new Adjacent(temp);
                    adjacentptr = nodeptr->adjacent;
                }
                else {
                    adjacentptr->next = new Adjacent(temp);
                    adjacentptr = adjacentptr->next;
                }
            }
            else {
                cout << "Node not found! " << endl;
            }
        }
        nodeptr = nodeptr->next;
    }
}

void printAdjacencyList() {
    nodeptr = start;
    while(nodeptr != NULL) {
        cout << nodeptr->data << " --> ";
        adjacentptr = nodeptr->adjacent;
        while(adjacentptr != NULL) {
            cout << adjacentptr->node->data << " ";
            adjacentptr = adjacentptr->next;
        }
        cout << endl;
        nodeptr = nodeptr->next;
    }
}

int main() {
    createGraph();
    printAdjacencyList();
    return 0;
}