#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minScoreTriangulation(vector<int> &values)
    {
        dp = vector<vector<int>>(50, vector<int>(50, 0));
        dividePolygon(values, 0, values.size() - 1);
        return dp[0][values.size() - 1];
    }

private:
    vector<vector<int>> dp;
    int dividePolygon(vector<int> &values, int left, int right)
    {
        if (right - left == 1)
            return 0;
        if (dp[left][right] != 0)
            return dp[left][right];
        int M = INT_MAX;;
        for (int i = left + 1; i < right; i++)
            M = min(M, dividePolygon(values, left, i) + dividePolygon(values, i, right) + values[left] * values[i] * values[right]);
        return dp[left][right] = M;
    }
};