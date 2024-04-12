#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        int leftmax = height[0];
        int rightmax = height[height.size() - 1];

        for (int i = 0, j = height.size() - 1; i < j;)
        {
            leftmax = max(leftmax, height[i]);
            rightmax = max(rightmax, height[j]);
            ans += leftmax < rightmax ? leftmax - height[i++] : rightmax - height[j--];
        }
        return ans;
    }
};