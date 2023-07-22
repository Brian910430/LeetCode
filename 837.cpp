#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        if (k == 0 || n > k + maxPts)
            return 1;
        vector<double> record = vector<double>(n + 1, 0);
        double ans = 0, temp = 1;
        record[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            record[i] = temp / maxPts;
            if (i < k)
                temp += record[i];
            else
                ans += record[i];
            if (i >= maxPts)
                temp -= record[i - maxPts];
        }
        return ans;
    }
};