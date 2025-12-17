#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int ans = 0;
        while (1)
        {
            int m = INT_MAX;
            for (int left = 0, right = 0; right < nums.size();)
            {
                for (; left < nums.size() && nums[left] == 0; left++)
                    ;
                right = left;
                for (; right < nums.size() && nums[right] != 0; right++)
                    m = min(m, nums[right]);

                if (right - left > 0)
                {
                    for (int i = left; i < right; i++)
                        if (nums[i] == m)
                            nums[i] = 0;
                    ans++;
                }
                left = ++right;
                m = INT_MAX;
            }
            if (count(nums.begin(), nums.end(), 0) == nums.size())
                return ans;
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 5, 0, 2, 3, 0, 4};
    cout << solution.minOperations(nums) << endl;
    return 0;
}