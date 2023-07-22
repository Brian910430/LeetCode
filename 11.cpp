#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ans = INT_MIN;
        for (int i = 0, j = height.size() - 1; i < j;)
        {
            int temp = (j - i) * min(height[i], height[j]);
            if (ans < temp)
                ans = temp;
            if (height[i] > height[j])
                j--;
            else
                i++;
        }
        return ans;
    }
};