#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countBeautifulPairs(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (GCD(firstDigit(nums[i]), lastDigit(nums[j])) == 1)
                    ans++;
        return ans;
    }

private:
    int GCD(int i, int j)
    {
        if (j == 0)
            return i;
        i %= j;
        return GCD(j, i);
    }

    int firstDigit(int i)
    {
        while (i >= 10)
            i /= 10;
        return i;
    }

    int lastDigit(int i)
    {
        return i % 10;
    }
};