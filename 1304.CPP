#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sumZero(int n)
    {
        int sum = 0;
        vector<int> ans = vector<int>();
        for (int i = 1; i < n; i++)
        {
            ans.push_back(i);
            sum += i;
        }
        ans.push_back(sum * -1);
        return ans;
    }
};