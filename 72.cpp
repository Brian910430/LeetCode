#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> record(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            record[i][0] = i;
        for (int i = 0; i <= m; i++)
            record[0][i] = i;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (word1[i - 1] == word2[j - 1])
                    record[i][j] = record[i - 1][j - 1];
                else
                    record[i][j] = min({record[i - 1][j - 1], record[i - 1][j], record[i][j - 1]}) + 1;
        return record[n][m];
    }
};