#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestCombination(vector<int> &candidates)
    {
        int count = 0;
        int ans = 0;
        for (int i = 1; i <= 1e7; i <<= 1)
        {
            count = 0;
            for (int j = 0; j < candidates.size(); j++)
                count += (candidates[j] & i) > 0;
            ans = max(ans, count);
        }
        return ans;
    }
};
