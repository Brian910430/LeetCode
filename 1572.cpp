#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int ans = 0;

        for (int i = 0, j = n - 1; i < n; i++, j--)
        {
            ans += mat[i][i];
            ans += mat[i][j];
            if (i == j)
                ans -= mat[i][i];
        }
        return ans;
    }
};