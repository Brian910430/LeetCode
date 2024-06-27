#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        vector<int> isFlipped(nums.size() + 1, 0);
        int ans = 0;
        int flipped = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i >= k)
                flipped ^= isFlipped[i - k];
            if (flipped == nums[i])
            {
                if (i + k > nums.size())
                    return -1;
                ans++;
                flipped ^= 1;
                isFlipped[i] = 1;
            }
        }
        return ans;
    }
};