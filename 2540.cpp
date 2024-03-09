#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        for (int i = 0, j = 0; i < nums1.size() || j < nums2.size();)
        {
            int left = i >= nums1.size() ? INT_MAX : nums1[i];
            int right = j >= nums2.size() ? INT_MAX : nums2[j];
            if (left == right)
                return left;
            else if (left < right)
                i++;
            else
                j++;
        }
        return -1;
    }
};