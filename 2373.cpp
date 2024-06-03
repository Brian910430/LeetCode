#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> ans = vector<vector<int>>(n - 2, vector<int>(n - 2, 0));

        for (int i = 1; i < grid.size() - 1; i++)
            for (int j = 1; j < grid.size() - 1; j++)
            {
                int temp = 0;
                for (int k = i - 1; k <= i + 1; k++)
                    for (int l = j - 1; l <= j + 1; l++)
                        temp = max(temp, grid[k][l]);
                ans[i - 1][j - 1] = temp;
            }
        return ans;
    }
};