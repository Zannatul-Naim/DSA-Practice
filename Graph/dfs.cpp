#include<bits/stdc++.h>

using namespace std;

vector<int> dfs(vector<int>adjList[], int n) {
    vector<bool> visited(n, false);

    vector<int> dfs;

    stack<int> s;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            s.push(i);

            visited[i] = true;

            while(!s.empty()) {
                int node = s.top();
                s.pop();

                dfs.push_back(node);

                for(auto it : adjList[node]) {
                    if(!visited[i]) {
                        s.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }

    return dfs;

}

int main() {
    int n;
    cin >> n;

    vector<int>adjList[n];

    int edges;
    cin >> edges;

    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i = 0; i < n; i++) {
        cout << i << " : ";

        for(auto j : adjList[i]) cout << j << " ";
        cout << endl;
    }
    cout << endl;

    vector<int>ans = dfs(adjList, n);

    cout << "DFS result : ";
    for(auto it : ans) cout << it << " ";

    cout << endl;

    return 0;
}