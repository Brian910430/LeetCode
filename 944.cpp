#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int count = 0;
        int size = strs.size();
        int length = strs[0].length();
        int now = 0;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (now <= strs[j][i])
                    now = strs[j][i];
                else
                {
                    count++;
                    break;
                }
            }
            now = 0;
        }
        return count;
    }
};