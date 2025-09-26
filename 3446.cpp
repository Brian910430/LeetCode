#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size() - 1;
        for (int i = n; i >= 0; i--)
        {
            vector<int> temp = vector<int>();
            for (int j = 0; j <= n - i; j++)
                temp.push_back(grid[i + j][j]);
            sort(temp.begin(), temp.end(), greater<int>());
            for (int j = 0; j <= n - i; j++)
                grid[i + j][j] = temp[j];
        }
        for (int i = n; i > 0; i--)
        {
            vector<int> temp = vector<int>();
            for (int j = 0; j <= n - i; j++)
                temp.push_back(grid[j][i + j]);
            sort(temp.begin(), temp.end(), less<int>());
            for (int j = 0; j <= n - i; j++)
                grid[j][i + j] = temp[j];
        }
        return grid;
    }
};