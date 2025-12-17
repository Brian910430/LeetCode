#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int best = INT_MAX;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int gcd = nums[i];
            if (nums[i] == 1)
                count++;
            for (int j = i + 1; j < nums.size(); j++)
            {
                gcd = GCD(gcd, nums[j]);
                if (gcd == 1)
                {
                    best = min(best, j - i + 1);
                    break;
                }
            }
        }
        if (best == INT_MAX)
            return -1;
        return best - 1 + nums.size() - 1 - count;
    }

private:
    int GCD(int a, int b)
    {
        if (b == 0)
            return a;
        return GCD(b, a % b);
    }
};