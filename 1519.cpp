#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> adj;

public:
    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string label)
    {
        adj = vector<vector<int>>(n);
        vector<int> ans = vector<int>(n, 1);
        for (auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        };
        DFS(ans, label, 0);
        return ans;
    }

    vector<int> DFS(vector<int> &ans, string &label, int now)
    {
        vector<int> record(26, 0);
        record[label[now] - 'a']++;
        ans[now]--;
        for (int i : adj[now])
        {
            if (ans[i])
            {
                vector<int> temp = DFS(ans, label, i);
                for (int j = 0; j < 26; j++)
                    record[j] += temp[j];
            }
        }
        ans[now] = record[label[now] - 'a'];
        return record;
    }
};