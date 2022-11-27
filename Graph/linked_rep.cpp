#include <iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
class Node
{
public:
    int data;
    int status;
    Node *next;
    class Adjacent *adjacent;

    Node(int data)
    {
        this->data = data;
        this->status = 0;
        this->next = NULL;
        this->adjacent = NULL;
    }
};

class Adjacent
{
public:
    class Node *node;
    Adjacent *next;
    Adjacent(Node *node)
    {
        this->node = node;
        this->next = NULL;
    }
};

typedef Node node;
typedef Adjacent adjcent;

node *start = NULL, *nodeptr;
adjcent *adjacentptr = NULL;

class Graph
{
public:
    void createNodeList(int v)
    {
        node *tail = start;
        for (int i = 0; i < v; i++)
        {
            if (i == 0)
            {
                start = new Node(i);
                tail = start;
            }
            else
            {
                tail->next = new Node(i);
                tail = tail->next;
            }
        }
    }

    void printNodeList()
    {
        node *temp = start;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    node *findNodeForItem(int item)
    {
        node *temp = start;
        while (temp != NULL)
        {
            if (temp->data == item)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    void createGraph(int vertex)
    {
        createNodeList(vertex);
        printNodeList();

        nodeptr = start;
        while (nodeptr != NULL)
        {
            adjacentptr = NULL;
            cout << "Enter connected nodes with " << nodeptr->data << " (-1) for end : ";
            while (true)
            {
                int item;
                cin >> item;
                if (item == -1)
                    break;
                else if (findNodeForItem(item) != NULL)
                {
                    node *temp = findNodeForItem(item);
                    if (nodeptr->adjacent == NULL)
                    {
                        nodeptr->adjacent = new Adjacent(temp);
                        adjacentptr = nodeptr->adjacent;
                    }
                    else
                    {
                        adjacentptr->next = new Adjacent(temp);
                        adjacentptr = adjacentptr->next;
                    }
                }
                else
                {
                    cout << "Node not found! " << endl;
                }
            }
            nodeptr = nodeptr->next;
        }
    }

    void printAdjacencyList()
    {
        nodeptr = start;
        while (nodeptr != NULL)
        {
            cout << nodeptr->data << " --> ";
            adjacentptr = nodeptr->adjacent;
            while (adjacentptr != NULL)
            {
                cout << adjacentptr->node->data << " ";
                adjacentptr = adjacentptr->next;
            }
            cout << endl;
            nodeptr = nodeptr->next;
        }
    }

    
vector<int> bfs () {

    // vector<bool>vis(vertex, false);
    queue<node*>q;
    vector<int>bfs_result;
    q.push(start);
    start->status = 1;
    while(!q.empty()) {
        node *temp = q.front();
        q.pop();
        temp->status = 2;
        bfs_result.push_back(temp->data);
        adjacentptr = temp->adjacent;
        while(adjacentptr != NULL) {
            if(adjacentptr->node->status == 0) {
                q.push(adjacentptr->node);
                adjacentptr->node->status = 1;
            }
            adjacentptr = adjacentptr->next;
        }
    }
    return bfs_result;
}

vector<int> dfs () {
    vector<int>dfs_result;
    stack<node*>s;
    s.push(start);
    start->status = 1;
    while(!s.empty()) {
        node *temp = s.top();
        s.pop();
        dfs_result.push_back(temp->data);
        if(temp->status == 1) temp->status = 2;
        adjacentptr = temp->adjacent;
        while(adjacentptr != NULL) {
            if(adjacentptr->node->status == 0) {
                s.push(adjacentptr->node);
                adjacentptr->node->status = 1;
            }
            adjacentptr = adjacentptr->next;
        }
    }
    return dfs_result;
}

void reset() {
    nodeptr = start;
    while(nodeptr != NULL) {
        nodeptr->status = 0;
        nodeptr = nodeptr->next;
    }
}

};


int main()
{

    cout << "Enter number of vertexes : ";
    int vertex;
    cin >> vertex;
    Graph graph;
    graph.createGraph(vertex);
    graph.printAdjacencyList();

    graph.reset();
    vector<int> res = graph.bfs();

    cout << "BFS result : ";
    for(auto i : res) cout << i << " ";
    cout << endl;

    graph.reset();
    vector<int> dfs = graph.dfs();

    cout << "DFS result : ";
    for(auto i : dfs) cout << i << " ";
    cout << endl;

    return 0;
}

/*
input :
 
4

1 2 3 -1
0 3 -1
0 3 -1
0 1 2 -1

output : 

0 --> 1 2 3
1 --> 0 3
2 --> 0 3
3 --> 0 1 2

BFS result : 0 1 2 3
DFS result : 0 3 2 1
*/