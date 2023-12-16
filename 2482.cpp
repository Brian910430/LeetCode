#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row = vector<int>(n, 0);
        vector<int> col = vector<int>(m, 0);
        vector<vector<int>> ans = vector<vector<int>>(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j])
                {
                    row[i]++;
                    col[j]++;
                }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans[i][j] = 2 * row[i] + 2 * col[j] - n - m;
        return ans;
    }
};