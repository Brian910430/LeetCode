#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumEnergy(vector<int> &energy, int k)
    {
        int ans = INT_MIN;
        for (int i = energy.size() - 1; i >= 0; i--)
        {
            energy[i] = i + k < energy.size() ? energy[i] + energy[i + k] : energy[i];
            ans = max(ans, energy[i]);
        }
        return ans;
    }
};