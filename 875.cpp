#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        int right = *max_element(piles.begin(), piles.end());
        int left = 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int hours = 0;
            for (int i = 0; i < n; i++)
            {
                hours += piles[i] / mid + (piles[i] % mid > 0);
                if (hours > h)
                    break;
            }
            if (hours > h)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};