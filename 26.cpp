#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int index = 1;
        for (int i = 0; i < nums.size(); i++)
            if (nums[index - 1] != nums[i])
                nums[index++] = nums[i];
        return index;
    }
};

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int index = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map[nums[i]] == 0)
            {
                map[nums[i]] = 1;
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};