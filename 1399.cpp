#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countLargestGroup(int n)
    {
        vector<int> count(37, 0);
        int maxi = INT_MIN;
        int ans = 0;

        for (int i = 1; i <= n; i++)
            count[digitSum(i)]++;
        for (auto i : count)
        {
            if (i > maxi)
            {
                maxi = i;
                ans = 1;
            }
            else if (i == maxi)
                ans++;
        }
        return ans;
    }

private:
    int digitSum(int n)
    {
        int nums = 0;
        while (n)
        {
            nums += n % 10;
            n /= 10;
        }
        return nums;
    }
};