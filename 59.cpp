#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans = vector<vector<int>>(n, vector<int>(n, 0));
        int i = -1;
        int j = -1;
        int count = 1;
        int offset = 0;

        for (int round = 0; round <= n / 2; round++)
        {
            for (i = i + 1, j = j + 1; j < n - offset; j++)
                ans[i][j] = count++;
            for (i = i + 1, j = j - 1; i < n - offset; i++)
                ans[i][j] = count++;
            for (i = i - 1, j = j - 1; j >= offset; j--)
                ans[i][j] = count++;
            offset++;
            for (i = i - 1, j = j + 1; i >= offset; i--)
                ans[i][j] = count++;
        }
        return ans;
    }
};