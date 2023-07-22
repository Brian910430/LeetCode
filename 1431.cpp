#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int n = candies.size();
        int max = INT_MIN;
        vector<bool> ans = vector<bool>(n, false);
        for (int i = 0; i < n; i++)
            if (max < candies[i])
                max = candies[i];

        for (int i = 0; i < n; i++)
            if (candies[i] + extraCandies >= max)
                ans[i] = true;
        return ans;
    }
};