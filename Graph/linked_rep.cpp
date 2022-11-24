#include<iostream>

using namespace std;

class Node {
    public : 
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

typedef Node node;

struct vertex_list {
    Node * listHead;
};

struct Graph {
    int data;
    struct vertex_list *v_list;
};

typedef Graph graph;

graph * createGraph(int vertex) {
    int i;
    graph* va_list = new Graph;
    va_list->data = vertex;

    va_list->v_list = new vertex_list[vertex];

    for(int i = 0; i < vertex; i++) {
        va_list->v_list[i].listHead = NULL;
    }

    return va_list;
}


void addEdge(graph *g, int v1, int v2) {
    node *newNode1 = new Node(v1);
    node *newNode2 = new Node(v2);

    if(g->v_list[v2].listHead == NULL) g->v_list[v2].listHead = newNode1;
    else {
        newNode1->next = g->v_list[v2].listHead;
        g->v_list[v2].listHead = newNode2;
    }

    // for undirected
    if(g->v_list[v1].listHead == NULL) g->v_list[v1].listHead = newNode1;
    else {
        newNode2->next = g->v_list[v1].listHead;
        g->v_list[v1].listHead = newNode1;
    }
}

int main() {
    int i, vertex, edge;

    cout << "Enter number of vertex : ";
    cin >> vertex;

    graph *g = createGraph(vertex);

    cout << "Enter number of edges : ";
    cin >> edge;
    for(int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;

        addEdge(g, u, v);
    }

    cout << endl;

    for(int i = 0; i < vertex; i++) {
        cout << i << " --> ";
        node *temp = g->v_list[i].listHead;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    return 0;
}