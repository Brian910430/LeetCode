#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        vector<int> record = vector<int>(n, -1);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (ranges[i] == 0)
                continue;
            int left = max(0, i - ranges[i]);
            int right = min(n - 1, i + ranges[i]);
            record[left] = max(record[left], right);
        }
        for (int i = 0; i < n; i++)
        {
            ;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    return 0;
}