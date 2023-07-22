#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int n = gain.size();
        vector<int> record(n + 1, 0);
        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            record[i + 1] = record[i] + gain[i];
            ans = max(ans, record[i]);
        }
        ans = max(ans, record[n]);
        return ans;
    }
};