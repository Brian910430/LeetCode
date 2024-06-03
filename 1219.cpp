#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                ans = max(ans, DFS(grid, i, j));
        return ans;
    }

private:
    int DFS(vector<vector<int>> &grid, int i, int j)
    {
        if (i == -1 || j == -1 || i == grid.size() || j == grid[0].size() || grid[i][j] == 0)
            return 0;
        int temp = grid[i][j];
        int ans = 0;
        grid[i][j] = 0;
        ans = max(ans, temp + max({DFS(grid, i + 1, j), DFS(grid, i - 1, j), DFS(grid, i, j + 1), DFS(grid, i, j - 1)}));
        grid[i][j] = temp;
        return ans;
    }
};