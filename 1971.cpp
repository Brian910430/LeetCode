#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> map = vector<vector<int>>(n);
        vector<int> visited = vector<int>(n, 0);
        stack<int> s;
        int now;
        for (int i = 0; i < edges.size(); i++)
        {
            map[edges[i][0]].push_back(edges[i][1]);
            map[edges[i][1]].push_back(edges[i][0]);
        }
        s.push(source);

        while (s.size())
        {
            now = s.top();
            s.pop();
            visited[now] = 1;
            if (now == destination)
                return true;

            for (auto a : map[now])
                if (!visited[a])
                    s.push(a);
        }
        return false;
    }
};