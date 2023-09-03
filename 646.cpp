#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        if (pairs.size() == 0)
            return 0;
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        int ans = 1;
        int max = pairs[0][1];
        for (int i = 1; i < pairs.size(); i++)
        {
            if (max < pairs[i][0])
            {
                max = pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};