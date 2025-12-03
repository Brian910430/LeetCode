#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int last = -k - 5;
        for (int i = 0; i < nums.size(); i++)
        {
            cout << "i: " << i << ", nums[i]: " << nums[i] << ", last: " << last << endl;
            if (nums[i] == 1 && i - last <= k)
                return false;
            if (nums[i] == 1)
                last = i;
        }
        return true;
    }
};