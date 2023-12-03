#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPath(vector<int> &parent, string s)
    {
        int n = parent.size();
        graph.resize(n + 5, vector<int>());
        ans = 0;
        for (int i = 1; i < n; i++)
            graph[parent[i]].push_back(i);
        DFS(0, s);
        return ans;
    }

private:
    vector<vector<int>> graph;
    int ans;
    int DFS(int index, string &s)
    {
        int max1 = 0;
        int max2 = 0;
        for (auto child : graph[index])
        {
            int res = DFS(child, s);
            if (s[index] != s[child])
            {
                if (res > max1)
                {
                    max2 = max1;
                    max1 = res;
                }
                else if (res > max2)
                    max2 = res;
            }
        }
        ans = max(ans, max1 + max2 + 1);
        return max1 + 1;
    }
};