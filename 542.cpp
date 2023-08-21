#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        vector<vector<int>> ans = vector<vector<int>>(mat.size(), vector<int>(mat[0].size(), 0));
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> record;
        int step = 0;
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[0].size(); j++)
                if (mat[i][j] == 0)
                    record.push({i, j});

        while (record.size())
        {
            int n = record.size();
            step++;
            for (int i = 0; i < n; i++)
            {
                int x = record.front().first;
                int y = record.front().second;
                record.pop();
                for (int j = 0; j < 4; j++)
                {
                    int newX = x + dir[j][0];
                    int newY = y + dir[j][1];
                    if (0 <= newX && newX < mat.size() && 0 <= newY && newY < mat[0].size() && mat[newX][newY] == 1)
                    {
                        ans[newX][newY] = step;
                        mat[newX][newY] = 2;
                        record.push({newX, newY});
                    }
                }
            }
        }
        return ans;
    }
};