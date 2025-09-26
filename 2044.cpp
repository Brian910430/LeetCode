#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int orSum = 0;
        for (auto i : nums)
            orSum |= i;
        return backTrack(0, 0, orSum, nums);
    }

private:
    int backTrack(int index, int currentOr, int orSum, vector<int> &nums)
    {
        int count = 0;
        if (currentOr == orSum)
            count++;
        for (int i = index; i < nums.size(); i++)
            count += backTrack(i + 1, currentOr | nums[i], orSum, nums);
        return count;
    }
};