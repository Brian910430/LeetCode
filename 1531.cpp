#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getLengthOfOptimalCompression(string s, int k)
    {
        int n = s.length();
        vector<vector<int>> record(110, vector<int>(110, 9999));
        record[0][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                int cnt = 0, del = 0;
                for (int l = i; l >= 1; l--)
                {
                    if (s[l - 1] == s[i - 1])
                        cnt++;
                    else
                        del++;

                    if (j - del >= 0)
                        record[i][j] = min(record[i][j], record[l - 1][j - del] + 1 + (cnt >= 100 ? 3 : (cnt >= 10 ? 2 : (cnt >= 2 ? 1 : 0))));
                }
                if (j > 0)
                    record[i][j] = min(record[i][j], record[i - 1][j - 1]);
            }
        }
        return record[n][k];
    }
};