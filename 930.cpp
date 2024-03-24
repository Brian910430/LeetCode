#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int n = nums.size();
        int ans = 0;
        vector<int> prefix(n + 5, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];
        for (int i = 0; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
                if (prefix[j] - prefix[i] == goal)
                    ans++;
                else if (prefix[j] - prefix[i] > goal)
                    break;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 0, 1, 0, 1};
    cout << solution.numSubarraysWithSum(nums, 2) << endl;
    nums = {0, 0, 0, 0, 0};
    cout << solution.numSubarraysWithSum(nums, 0) << endl;
    return 0;
}