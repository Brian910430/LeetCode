#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans;
        for (int i = 0; i <= rowIndex; i++)
            ans.push_back(combination(rowIndex, i));
        return ans;
    }

    int combination(int a, int b)
    {
        if (b > a - b)
            return combination(a, a - b);
        long long ans = 1;
        for (int i = 1; i <= b; i++)
            (ans *= a--) /= i;
        return ans;
    }
};