#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        bool found = false;
        queue<pair<int, int>> q;
        moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!found && grid[i][j] == 1)
                {
                    findFirstIsland(i, j, n, m, grid);
                    found = true;
                }
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        while (q.size())
        {
            int size = q.size();
            ans++;
            while (size--)
            {
                pair<int, int> now = q.front();
                q.pop();
                for (auto move : moves)
                {
                    int x = now.first + move[0];
                    int y = now.second + move[1];
                    if (x >= 0 && x < n && y >= 0 && y < m)
                    {
                        if (grid[x][y] == 0)
                        {
                            q.push({x, y});
                            grid[x][y] = 2;
                        }
                        else if (grid[x][y] == 1)
                            return ans - 1;
                    }
                }
            }
        }
        return 0;
    }

private:
    void findFirstIsland(int i, int j, int n, int m, vector<vector<int>> &grid)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1)
            return;
        grid[i][j] = 2;
        for (auto move : moves)
            findFirstIsland(i + move[0], j + move[1], n, m, grid);
    }
    vector<vector<int>> moves;
};