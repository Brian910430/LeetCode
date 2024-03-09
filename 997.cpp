#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> map = vector<int>(n + 1, 0);
        vector<int> trusts = vector<int>(n + 1, 1);

        for (int i = 0; i < trust.size(); i++)
        {
            map[trust[i][1]]++;
            trusts[trust[i][0]] = 0;
        }
        for (int i = 1; i <= n; i++)
            if (trusts[i] && map[i] == n - 1)
                return i;
        return -1;
    }
};