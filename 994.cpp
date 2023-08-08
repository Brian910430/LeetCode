#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int ans = 0;
        int numFresh = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> waiting;
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 2)
                    waiting.push({i, j});
                else if (grid[i][j] == 1)
                    numFresh++;

        while (waiting.size() && numFresh)
        {
            int count = waiting.size();
            while (count--)
            {
                int nowX = waiting.front()[0];
                int nowY = waiting.front()[1];
                waiting.pop();

                for (int i = 0; i < 4; i++)
                {
                    int x = nowX + direction[i][0];
                    int y = nowY + direction[i][1];
                    if (0 <= x && x < m && 0 <= y && y < n && grid[x][y] == 1)
                    {
                        waiting.push({x, y});
                        grid[x][y] = 2;
                        numFresh--;
                    }
                }
            }
            ans++;
        }
        return numFresh == 0 ? ans : -1;
    }
};