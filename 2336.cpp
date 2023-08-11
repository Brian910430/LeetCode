#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet
{
public:
    SmallestInfiniteSet()
    {
        now = 1;
        record.clear();
    }

    int popSmallest()
    {
        if (record.empty())
            return now++;

        int ans = *record.begin();
        record.erase(record.begin());
        return ans;
    }

    void addBack(int num)
    {
        if (num < now)
            record.insert(num);
    }

private:
    set<int> record;
    int now;
};