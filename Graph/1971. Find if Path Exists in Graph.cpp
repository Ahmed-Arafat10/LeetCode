#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    stack<int> st;
public:
    bool dfs(int s_node, int d_node, vector<vector<int>> &adj, bool *vis)
    {
        vis[s_node] = 1;
        st.push(s_node);
        while (!st.empty())
        {
            int cur = st.top();
            if (cur == d_node) return 1;
            st.pop();
            for (auto &child : adj[cur])
            {
                if (!vis[child]) vis[child] = 1, st.push(child);
            }
        }
        return 0;
    }
    int validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> adj(n);
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        return dfs(source, destination, adj, vis);
    }
};
