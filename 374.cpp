#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int guessNumber(int n)
    {
        int ans = 0;
        int left = 1;
        int right = n;
        while (1)
        {
            int now = left + (right - left) / 2;
            int feedback = guess(now);
            if (feedback == 0)
                return now;
            else if (feedback == -1)
                right = now - 1;
            else
                left = now + 1;
        }
    }
};