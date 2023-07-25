#include <bits/stdc++.h>
using namespace std;

class RecentCounter
{
public:
    RecentCounter()
    {
        ;
    }

    int ping(int t)
    {
        record.push(t);
        while (record.front() < t - 3000)
            record.pop();
        return record.size();
    }

private:
    queue<int> record;
};