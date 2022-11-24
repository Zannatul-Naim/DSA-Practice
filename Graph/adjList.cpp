#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adjList;

class Graph {
    public:

    Graph(int n) {
        adjList.resize(n+1);
    }

    void addEdge(int src, int dest, bool flag) {
        adjList[src].push_back(dest);
        if(flag) adjList[dest].push_back(src);
    }

    void printGraph() {
        for(int i = 1; i <= adjList.size()-1; i++) {
            cout << i << " -> ";
            for(auto j : adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    int n;
    cout << "Enter number of nodes : ";
    cin >> n;

    Graph graph(n);
    graph.addEdge(1, 2, true);
    graph.addEdge(1, 3, true);
    graph.addEdge(1, 4, true);
    graph.addEdge(2, 4, true);
    graph.addEdge(2, 5, true);
    graph.addEdge(3, 4, true);
    graph.addEdge(4, 5, true);

    graph.printGraph();
}  
