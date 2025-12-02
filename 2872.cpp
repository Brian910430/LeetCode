#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
    {
        vector<unordered_set<int>> adjList(n, unordered_set<int>());
        ans = 0;

        for (auto edge : edges)
        {
            adjList[edge[0]].insert(edge[1]);
            adjList[edge[1]].insert(edge[0]);
        }
        dfs(0, -1, adjList, values, k);
        return ans;
    }

private:
    int ans;
    int dfs(int node, int parent, vector<unordered_set<int>> &adjList, vector<int> &values, int k)
    {
        int sum = values[node];
        for (auto i : adjList[node])
            if (i != parent)
                sum += dfs(i, node, adjList, values, k);
        if (sum % k == 0)
        {
            ans++;
            return 0;
        }
        return sum % k;
    }
};