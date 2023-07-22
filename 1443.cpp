#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> map;
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        map.resize(n);
        for (auto i : edges)
        {
            map[i[0]].push_back(i[1]);
            map[i[1]].push_back(i[0]);
        }
        return DFS(0, -1, hasApple) * 2;
    }

    int DFS(int now, int parent, vector<bool> &hasApple)
    {
        int count = 0;
        for (auto i : map[now])
            if (i != parent)
                count += DFS(i, now, hasApple);
        if (now && (count || hasApple[now]))
            count++;
        return count;
    }
};