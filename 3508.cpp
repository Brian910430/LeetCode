#include <bits/stdc++.h>
using namespace std;

class Router
{
public:
    Router(int memoryLimit) : n(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp)
    {
        long long key = hash(source, destination, timestamp);
        if (packets.find(key) != packets.end())
            return false;
        if (q.size() == n)
            forwardPacket();
        q.push(key);
        counts[destination].push_back(timestamp);
        packets[key] = {source, destination, timestamp};
        return true;
    }

    vector<int> forwardPacket()
    {
        if (q.size() == 0)
            return {};
        long long key = q.front();
        vector<int> packet = packets[key];
        q.pop();
        packets.erase(key);
        counts[packet[1]].erase(counts[packet[1]].begin());
        return packet;
    }

    int getCount(int destination, int startTime, int endTime)
    {
        auto iter1 = upper_bound(counts[destination].begin(), counts[destination].end(), endTime);
        auto iter2 = lower_bound(counts[destination].begin(), counts[destination].end(), startTime);
        return iter1 - iter2;
    }

private:
    long long hash(int source, int destination, int timestamp)
    {
        return ((long long)source << 40) | ((long long)destination << 20) | timestamp;
    }
    int n;
    unordered_map<long long, vector<int>> packets;
    unordered_map<int, vector<int>> counts;
    queue<long long> q;
};