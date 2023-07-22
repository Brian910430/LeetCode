#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        long long total = 0;
        long long ans = INT_MIN;
        int index = 0;
        for (; index < k; index++)
            total += nums[index];
        ans = total;
        for (int i = 0; index < nums.size(); index++, i++)
        {
            total += nums[index] - nums[i];
            ans = max(ans, total);
        }
        return (double)ans / k;
    }
};

int main()
{
    Solution solution;
    return 0;
}