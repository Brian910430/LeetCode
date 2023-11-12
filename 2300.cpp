#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); i++)
            spells[i] = binarySearch(potions, spells[i], success);
        return spells;
    }

private:
    int binarySearch(vector<int> &potions, int spell, long long success)
    {
        int left = 0;
        int right = potions.size() - 1;
        int mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (1ll * spell * potions[mid] < success)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return potions.size() - left;
    }
};