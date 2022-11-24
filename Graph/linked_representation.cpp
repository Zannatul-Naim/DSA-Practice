#include<iostream>

using namespace std;

int vertex;

class Node {

  public:
    int data;
    Node *next;
    int status;
    struct Adjacent *adj;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->adj = NULL;
        this->status = 0;
    }
};

typedef Node node;

struct Adjacent {
    node *dest;
    struct Adjacent *adj;
};

typedef Adjacent adjacent;

node *start = NULL, *ptr;
adjacent *adjptr = NULL;

void create_node_list(int item) {

    for(int i = 0; i < item; i++) {
        if(i == 0) {
            start = new Node(i);
            ptr = start;
        }
        else {
            ptr->next = new Node(i);
            ptr = ptr->next;
        }
    }
}

adjacent* createAdjacent(node *temp_node) {
    adjacent *temp_adjacent = new adjacent;
    temp_adjacent->dest = temp_node;
    temp_adjacent->adj = NULL;

    return temp_adjacent;
}


void createGraph() {
    
    // int vertex;
    cout << "Enter number of vertices in the graph : ";
    cin >> vertex;
    create_node_list(vertex);

    ptr = start;
    for(int i = 0; i < vertex; i++) {

        cout << "Enter neighbours of " << i << " (-1 to stop) : ";
        node *temp = start;
        while(true) {
            int item;
            cin >> item;
            create_node_list(item);
            if(item == -1) break;

            while(true) {  // search for the specific node
                if(temp == NULL) {
                    cout << "node not found!" << endl;
                    break;
                }
                if(temp->data == item) {
                    if(ptr->adj == NULL) {
                        ptr->adj = createAdjacent(temp);
                        adjptr = ptr->adj;
                    }
                    else {
                        adjptr = createAdjacent(temp);
                        adjptr = adjptr->adj;
                    }
                }
                temp = temp->next;
            }
        }
        ptr = ptr->next;
    }
}

// Display the adjacency list

void display() {
    node* temp = start;
    for(int i = 0; i < vertex; i++) {
        cout << "Adjacent of " << i << " --> ";
        adjptr = temp->adj;
        while(adjptr != NULL) {
            cout << adjptr->dest->data;
            adjptr = adjptr->adj;
        }
        cout << endl;
        temp = temp->next;
    }
}

void printNodeList() {
    node *temp = start;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    
    // createGraph();
    // display();
    // create_node_list();
    printNodeList();
    cout << start->data << "\n ";
    return 0;
}