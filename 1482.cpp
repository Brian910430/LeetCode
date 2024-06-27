#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        if ((long long)m * k > bloomDay.size())
            return -1;
        int left = 1;
        int right = INT_MAX - 1;
        int middle;

        while (left < right)
        {
            middle = (right + left) / 2;
            if (canMake(bloomDay, m, k, middle))
                right = middle;
            else
                left = middle + 1;
        }
        return left;
    }

private:
    bool canMake(vector<int> &bloomDay, int m, int k, int day)
    {
        int total = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            int count = 0;
            while (i < bloomDay.size() && count < k && bloomDay[i] <= day)
            {
                count++;
                i++;
            }
            if (count == k)
            {
                total++;
                i--;
            }
            if (total >= m)
                return true;
        }
        return false;
    }
};