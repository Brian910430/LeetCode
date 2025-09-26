#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        vector<int> ans = vector<int>();
        for (int i = 1; i <= n; i++)
            if (noZero(i) && noZero(n - i))
            {
                ans.push_back(i);
                ans.push_back(n - i);
                return ans;
            }
        return ans;
    }

private:
    bool noZero(int n)
    {
        while (n)
        {
            if (n % 10 == 0)
                return false;
            n /= 10;
        }
        return true;
    }
};