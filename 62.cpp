#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> record(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                record[i][j] = record[i - 1][j] + record[i][j - 1];
        return record[m - 1][n - 1];
    }
};