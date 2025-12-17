#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTriples(int n)
    {
        int ans = 0;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= i; j++)
            {
                auto c = sqrt(i * i + j * j);
                if (c == (int)c && c <= n)
                    ans += 2;
            }
        return ans;
    }
};