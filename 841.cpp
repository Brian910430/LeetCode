#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<bool> visited(rooms.size(), false);
        queue<int> waitingRoom;
        waitingRoom.push(0);

        while (waitingRoom.size())
        {
            int now = waitingRoom.front();
            waitingRoom.pop();
            if (visited[now])
                continue;
            visited[now] = true;
            for (auto i : rooms[now])
                waitingRoom.push(i);
        }
        for (auto i : visited)
            if (!i)
                return false;
        return true;
    }
};