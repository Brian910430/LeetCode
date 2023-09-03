#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        vector<vector<int>> ans(row, vector<int>(column, 0));
        for (int i = 0; i < row; i++)
            if (obstacleGrid[i][0])
                break;
            else
                ans[i][0] = 1;
        for (int i = 0; i < column; i++)
            if (obstacleGrid[0][i])
                break;
            else
                ans[0][i] = 1;
        for (int i = 1; i < row; i++)
            for (int j = 1; j < column; j++)
                if (obstacleGrid[i][j] == 0)
                    ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
        return ans[row - 1][column - 1];
    }
};