#include <bits/stdc++.h>
using namespace std;

class Solution
{
    double solution(vector<int> &a, vector<int> &b)
    {
        int a_length = a.size();
        int b_length = b.size();
        int start = 0, end = a_length;
        while (start <= end)
        {
            int a_pivot = (start + end) / 2;
            int b_pivot = (a_length + b_length + 1) / 2 - a_pivot;
            int a_left = (a_pivot == 0) ? INT_MIN : a[a_pivot - 1];
            int a_right = (a_pivot == a_length) ? INT_MAX : a[a_pivot];
            int b_left = (b_pivot == 0) ? INT_MIN : b[b_pivot - 1];
            int b_right = (b_pivot == b_length) ? INT_MAX : b[b_pivot];
            if (a_left <= b_right && a_right >= b_left)
            {
                if ((a_length + b_length) % 2)
                    return max(a_left, b_left);
                else
                    return (max(a_left, b_left) + min(a_right, b_right)) / 2.0;
            }
            else if (a_left > b_right)
                end = a_pivot - 1;
            else
                start = a_pivot + 1;
        }
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        return n <= m ? solution(nums1, nums2) : solution(nums2, nums1);
    }
};