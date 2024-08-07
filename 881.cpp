#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int l = 0;
        int r = people.size() - 1;
        int ans = 0;

        sort(people.begin(), people.end(), greater<int>());
        while (l <= r)
            if (people[l] + people[r] <= limit)
                l++, r--, ans++;
            else
                ans++, l++;
        return ans;
    }
};