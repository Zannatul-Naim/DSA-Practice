
  class Solution {
public:

    int dfs(vector < vector < int > > &ed, int x, vector < bool > &has, vector < bool > &&seen) {
        seen[x] = true;
        int total = 0;
        for(auto i : ed[x]) {
            if(seen[i]) continue;
            int cst = dfs(ed, i, has, move(seen));
            if(cst > 0 || has[i]) {
                total += (cst + 2);
            }
        }
        return total;

    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

        return dfs(graph, 0, hasApple, vector < bool > (n));

    }
};
