#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        int ans = 0;
        vector<bool> visited(n, false);
        vector<vector<pair<int, int>>> map(n);
        queue<int> waitingCity;
        waitingCity.push(0);
        for (auto i : connections)
        {
            map[i[0]].push_back({i[1], 1});
            map[i[1]].push_back({i[0], 0});
        }

        while (waitingCity.size())
        {
            int now = waitingCity.front();
            waitingCity.pop();
            if (visited[now])
                continue;
            visited[now] = true;
            for (auto road : map[now])
            {
                waitingCity.push(road.first);
                ans += (!visited[road.first] && road.second);
            }
        }
        return ans;
    }
};