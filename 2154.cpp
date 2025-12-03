#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findFinalValue(vector<int> &nums, int original)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        while (true)
        {
            if (numSet.count(original))
                original <<= 1;
            else
                return original;
        }
        return original;
    }
};