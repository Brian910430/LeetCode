#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> record(n, vector<int>(n / 2 + 1, 0));
        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 1; i >= 1; i--)
            suffixSum[i - 1] = suffixSum[i] + piles[i - 1];
        return findBest(piles, suffixSum, record, 0, 1);
    }

private:
    int findBest(vector<int> &piles, vector<int> &suffixSum, vector<vector<int>> &record, int i, int m)
    {
        if (i >= piles.size())
            return 0;
        if (i + 2 * m >= piles.size()) return suffixSum[i];
        if (record[i][m] != 0)
            return record[i][m];
        int best = 0;
        for (int x = 1; x <= 2 * m; x++)
            best = max(best, suffixSum[i] - findBest(piles, suffixSum, record, i + x, max(m, x)));
        record[i][m] = best;
        return best;
    }
};