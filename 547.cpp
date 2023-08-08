#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int now = 0;
        bool allVisited = false;
        int ans = 0;

        visited.resize(isConnected.size(), false);
        while (!allVisited)
        {
            visit(isConnected, now);
            ans++;
            allVisited = true;
            for (int i = 0; i < visited.size(); i++)
                if (!visited[i])
                {
                    now = i;
                    allVisited = false;
                }
        }
        return ans;
    }

private:
    vector<bool> visited;
    void visit(vector<vector<int>> &isConnected, int now)
    {
        if (visited[now])
            return;
        visited[now] = true;
        for (int i = 0; i < isConnected[now].size(); i++)
            if (isConnected[now][i])
                visit(isConnected, i);
    }
};