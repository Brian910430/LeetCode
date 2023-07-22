#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        queue<int> Radiant = queue<int>();
        queue<int> Dire = queue<int>();
        for (int i = 0; i < senate.length(); i++)
            if (senate[i] == 'R')
                Radiant.push(i);
            else
                Dire.push(i);

        int lineUp = senate.length();
        while (Radiant.size() && Dire.size())
        {
            if (Radiant.front() < Dire.front())
                Radiant.push(lineUp++);
            else
                Dire.push(lineUp++);
            Radiant.pop();
            Dire.pop();
        }
        if (Radiant.empty())
            return "Dire";
        else
            return "Radiant";
    }
};