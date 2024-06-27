#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int ans = INT_MAX;

        BFS(grid);
        pq.push({grid[0][0], {0, 0}});
        while (pq.size())
        {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int c = pq.top().first;
            pq.pop();
            if (visited[x][y])
                continue;
            visited[x][y] = 1;
            ans = min(ans, c);
            if (x == grid.size() - 1 && y == grid[0].size() - 1)
                break;

            if (x > 0 && !visited[x - 1][y])
                pq.push({grid[x - 1][y], {x - 1, y}});
            if (y > 0 && !visited[x][y - 1])
                pq.push({grid[x][y - 1], {x, y - 1}});
            if (x < grid.size() - 1 && !visited[x + 1][y])
                pq.push({grid[x + 1][y], {x + 1, y}});
            if (y < grid[0].size() - 1 && !visited[x][y + 1])
                pq.push({grid[x][y + 1], {x, y + 1}});
        }
        return ans;
    }

private:
    void BFS(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int count = 0;

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1)
                    q.push({i, j});
                else
                    grid[i][j] = -1;

        while (q.size())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (count && grid[x][y] != -1)
                    continue;
                if (x > 0 && grid[x - 1][y] == -1)
                    q.push({x - 1, y});
                if (y > 0 && grid[x][y - 1] == -1)
                    q.push({x, y - 1});
                if (x < grid.size() - 1 && grid[x + 1][y] == -1)
                    q.push({x + 1, y});
                if (y < grid[0].size() - 1 && grid[x][y + 1] == -1)
                    q.push({x, y + 1});
                grid[x][y] = count;
            }
            count++;
        }
    }
};