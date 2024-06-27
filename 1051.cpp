#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> copy = heights;
        int ans = 0;

        sort(copy.begin(), copy.end());
        for (int i = 0; i < heights.size(); i++)
            if (copy[i] != heights[i])
                ans++;
        return ans;
    }
};