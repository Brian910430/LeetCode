#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int total = 0;
        int ans = 0;

        for (int i = 0; i < minutes; i++)
            total += grumpy[i] ? customers[i] : 0;
        ans = total;
        for (int i = 1; i <= customers.size() - minutes; i++)
        {
            total -= grumpy[i - 1] ? customers[i - 1] : 0;
            total += grumpy[i + minutes - 1] ? customers[i + minutes - 1] : 0;
            ans = max(ans, total);
        }
        for (int i = 0; i < customers.size(); i++)
            ans += grumpy[i] ? 0 : customers[i];
        return ans;
    }
};