#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        n++;
        vector<int> record = vector<int>(n, -1);
        int edge = 0;
        int farest = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (ranges[i] == 0)
                continue;
            int left = max(0, i - ranges[i]);
            int right = i + ranges[i];
            record[left] = max(record[left], right);
        }
        for (int i = 0; i < n; i++)
        {
            if (i > edge)
            {
                if (farest <= edge)
                    return -1;
                ans++;
                edge = farest;
            }
            farest = max(farest, record[i]);
        }
        return ans;
    }
};