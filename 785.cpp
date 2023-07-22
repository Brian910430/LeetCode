#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        int start = 0;
        vector<char> team = vector<char>(n, 'c');

        while (start < graph.size())
        {
            queue<int> q = queue<int>();
            q.push(start);
            team[start] = 'a';

            while (q.size())
            {
                int now = q.front();
                q.pop();
                for (auto i : graph[now])
                {
                    if (team[i] != 'c')
                    {
                        if (team[i] == team[now])
                            return false;
                    }
                    else
                    {
                        if (team[now] == 'a')
                            team[i] = 'b';
                        else
                            team[i] = 'a';
                        q.push(i);
                    }
                }
            }
            while (start < graph.size() && team[start] != 'c')
                start++;
        }
        return true;
    }
};