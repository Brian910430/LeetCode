#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> record(n, vector<int>(m, 0));

        record[0][0] = text1[0] == text2[0];
        for (int i = 1; i < m; i++)
            if (text1[0] == text2[i])
                record[0][i] = 1;
            else
                record[0][i] = record[0][i - 1];
        for (int i = 1; i < n; i++)
            if (text1[i] == text2[0])
                record[i][0] = 1;
            else
                record[i][0] = record[i - 1][0];
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (text1[i] == text2[j])
                    record[i][j] = record[i - 1][j - 1] + 1;
                else
                    record[i][j] = max(record[i - 1][j], record[i][j - 1]);
        return record[n - 1][m - 1];
    }
};