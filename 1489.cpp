#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        for (int i = 0; i < edges.size(); i++)
            edges[i].push_back(i);
        sort(edges.begin(), edges.end(), [](auto &a, auto &b)
             { return a[2] < b[2]; });

        int minCost = buildMST(n, edges, -1, -1);
        vector<vector<int>> ans(2);
        for (int i = 0; i < edges.size(); i++)
        {
            if (buildMST(n, edges, i, -1) > minCost)
                ans[0].push_back(edges[i][3]);
            else if (buildMST(n, edges, -1, i) == minCost)
                ans[1].push_back(edges[i][3]);
        }
        return ans;
    }

private:
    int findParent(int a, vector<int> &parent)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = findParent(parent[a], parent);
    }

    int buildMST(int n, vector<vector<int>> &edges, int skip, int must)
    {
        vector<int> parent = vector<int>(n, 0);
        int totalWeight = 0;
        for (int i = 0; i < n; i++)
            parent[i] = i;

        if (must != -1)
        {
            totalWeight += edges[must][2];
            parent[findParent(edges[must][0], parent)] = findParent(edges[must][1], parent);
        }

        for (int i = 0; i < edges.size(); i++)
        {
            if (i == skip)
                continue;
            if (findParent(edges[i][0], parent) == findParent(edges[i][1], parent))
                continue;
            totalWeight += edges[i][2];
            parent[findParent(edges[i][0], parent)] = findParent(edges[i][1], parent);
        }

        for (int i = 0; i < n; i++)
            if (findParent(i, parent) != findParent(0, parent))
                return INT_MAX;
        return totalWeight;
    }
};