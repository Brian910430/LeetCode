#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
    {
        for (int i = 0; i < n; i++)
            if (group[i] == -1)
                group[i] = m++;
        vector<vector<int>> itemGraph(n, vector<int>());
        vector<vector<int>> groupGraph(m, vector<int>());
        unordered_map<int, vector<int>> orderedGroups;
        vector<int> itemBefore(n, 0);
        vector<int> groupBefore(m, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++)
            for (int j : beforeItems[i])
            {
                itemGraph[j].push_back(i);
                itemBefore[i]++;
                if (group[i] != group[j])
                {
                    groupGraph[group[j]].push_back(group[i]);
                    groupBefore[group[i]]++;
                }
            }

        vector<int> itemOrder = topologicalSort(itemGraph, itemBefore);
        vector<int> groupOrder = topologicalSort(groupGraph, groupBefore);

        if (itemOrder.empty() || groupOrder.empty())
            return vector<int>();
        for (auto i : itemOrder)
            orderedGroups[group[i]].push_back(i);
        for (auto i : groupOrder)
            for (auto j : orderedGroups[i])
                ans.push_back(j);

        return ans;
    }

    vector<int> topologicalSort(vector<vector<int>> &graph, vector<int> &before)
    {
        vector<int> visited;
        queue<int> q;
        for (int i = 0; i < before.size(); i++)
            if (before[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            visited.push_back(now);

            for (auto n : graph[now])
            {
                before[n]--;
                if (before[n] == 0)
                    q.push(n);
            }
        }

        return visited.size() == graph.size() ? visited : vector<int>();
    }
};