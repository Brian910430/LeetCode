#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n, vector<int>());
        vector<vector<int>> ans(n, vector<int>());

        for (auto i : edges)
            graph[i[1]].push_back(i[0]);
        for (int i = 0; i < n; i++)
        {
            vector<int> visited(n, 0);
            dfs(i, graph, visited, ans, i);
        }
        for (int i = 0; i < n; i++)
            sort(ans[i].begin(), ans[i].end());
        return ans;
    }

private:
    void dfs(int node, vector<vector<int>> &graph, vector<int> &visited, vector<vector<int>> &ans, int root)
    {
        if (visited[node])
            return;
        visited[node] = 1;
        if (node != root)
            ans[root].push_back(node);
        for (auto i : graph[node])
            dfs(i, graph, visited, ans, root);
    }
};