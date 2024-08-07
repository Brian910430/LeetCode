#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        long long ans = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        for (int i = 0; i < k; i++)
            if (happiness[i] < i)
                ans += 0;
            else
                ans += happiness[i] - i;
        return ans;
    }
};