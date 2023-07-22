#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long matrixSumQueries(int n, vector<vector<int>> &queries)
    {
        vector<bool> row = vector<bool>(n, false);
        vector<bool> column = vector<bool>(n, false);
        long long ans = 0;
        int row_count = 0;
        int column_count = 0;

        for (int i = queries.size() - 1; i >= 0; i--)
        {
            if (queries[i][0] == 0)
            {
                if (row[queries[i][1]])
                    continue;
                row[queries[i][1]] = true;
                row_count++;
                ans += (n - column_count) * queries[i][2];
            }
            else
            {
                if (column[queries[i][1]])
                    continue;
                column[queries[i][1]] = true;
                column_count++;
                ans += (n - row_count) * queries[i][2];
            }
        }
        return ans;
    }
};