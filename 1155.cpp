#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRollsToTarget(int n, int k, int target)
    {
        MOD = 1e9 + 7;
        record = vector<vector<int>>(n + 1, vector<int>(target + 5, -1));
        return backTrack(n, k, target);
    }

private:
    vector<vector<int>> record;
    int MOD;
    int backTrack(int n, int k, int target)
    {
        if (record[n][target] != -1)
            return record[n][target];
        if (n == 0 && target == 0)
            return 1;
        if (n == 0 || target == 0)
            return 0;
        int ans = 0;
        for (int i = 1; i <= min(k, target); i++)
            ans = (ans + backTrack(n - 1, k, target - i)) % MOD;
        return record[n][target] = ans;
    }
};