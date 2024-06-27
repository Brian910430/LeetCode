#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        unordered_map<int, int> record;

        for (int i = 0; i < nums.size(); i++)
            record[nums[i]]++;
        for (int i = 0, j = 0; j < 3; j++)
            for (int k = 0; k < record[j]; k++, i++)
                nums[i] = j;
    }
};