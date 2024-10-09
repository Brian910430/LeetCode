#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        vector<int> remainder(k, 0);
        for (int i : arr)
            remainder[(i % k + k) % k]++;
        if (remainder[0] % 2 != 0)
            return false;

        for (int i = 1; i <= k / 2; i++)
        {
            if (i == k - i)
                return remainder[i] % 2 == 0;
            else if (remainder[i] != remainder[k - i])
                return false;
        }
        return true;
    }
};