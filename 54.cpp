#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int i = -1;
        int j = -1;
        int total = m * n;
        int offset = 0;

        for (int round = 0; round <= min(n, m) / 2; round++)
        {
            for (i = i + 1, j = j + 1; j < m - offset && total > 0; j++)
            {
                ans.push_back(matrix[i][j]);
                total--;
            }
            for (i = i + 1, j = j - 1; i < n - offset && total > 0; i++)
            {
                ans.push_back(matrix[i][j]);
                total--;
            }
            for (i = i - 1, j = j - 1; j >= offset && total > 0; j--)
            {
                ans.push_back(matrix[i][j]);
                total--;
            }
            offset++;
            for (i = i - 1, j = j + 1; i >= offset && total > 0; i--)
            {
                ans.push_back(matrix[i][j]);
                total--;
            }
        }
        return ans;
    }
};