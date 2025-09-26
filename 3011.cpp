#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        vector<int> record;
        int right_min = INT_MAX;
        int right_max = INT_MIN;
        int left_max = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
            record.push_back(countBits(nums[i]));
        int bits = record[0];

        for (int i = 0; i < record.size(); i++)
        {
            if (bits == record[i])
            {
                if (right_min > nums[i])
                    right_min = nums[i];
                if (right_max < nums[i])
                    right_max = nums[i];
            }
            else
            {
                bits = record[i];
                if (right_min < left_max)
                    return false;
                left_max = right_max;
                right_min = nums[i];
                right_max = nums[i];
            }
        }
        return right_min >= left_max;
    }

private:
    int countBits(int num)
    {
        int count = 0;
        while (num)
        {
            count += num & 1;
            num /= 2;
        }
        return count;
    }
};