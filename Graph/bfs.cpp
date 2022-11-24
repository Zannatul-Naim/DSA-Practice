#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int>adjList[], int n) {
    vector<bool>vis(n, false);
    vector<int>bfs;
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            q.push(i);
            vis[i] = true;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it : adjList[node]) {
                    if(!vis[it]) {
                        q.push(it);
                        vis[it] = true;
                    }
                }
            }
        }
    }
    return bfs;
}

int main() {
    cout << "Enter number of Nodes : ";
    int n;
    cin >> n;
    vector<int>adjList[n];
    cout << "Enter number of Edges : ";
    int e;
    cin >> e;
    cout << "Enter Edges : \n";
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i = 0; i < n; i++) {
        cout << i << " : "; 
        for(auto i : adjList[i]) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
    vector<int>ans = bfs(adjList, n);

    for(auto it : ans) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}


/*

6 9
0 1
0 2
0 3
1 3
1 4
1 5
2 3
3 5
4 5

*/