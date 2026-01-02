#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>> &events)
    {
        vector<int> ans(numberOfUsers, 0);
        vector<int> attend(numberOfUsers, 1);
        for (int i = 0; i < events.size(); i++)
            if (events[i][0] == "OFFLINE")
                events.push_back({"ONLINE", to_string(stoi(events[i][1]) + 60), events[i][2]});
        sort(events.begin(), events.end(), cmp);

        for (auto &event : events)
        {
            if (event[0] == "OFFLINE")
                attend[stoi(event[2])] = 0;
            else if (event[0] == "ONLINE")
                attend[stoi(event[2])] = 1;
            else if (event[2] == "ALL")
                for (int i = 0; i < numberOfUsers; i++)
                    ans[i]++;
            else if (event[2] == "HERE")
                for (int i = 0; i < numberOfUsers; i++)
                    ans[i] += attend[i];
            else
            {
                stringstream ss(event[2]);
                string num;
                while (ss >> num)
                    ans[stoi(num.substr(2))]++;
            }
        }
        return ans;
    }

private:
    static bool cmp(vector<string> &a, vector<string> &b)
    {
        if (stoi(a[1]) == stoi(b[1]))
            return a[0] == "OFFLINE" || a[0] == "ONLINE";
        return stoi(a[1]) < stoi(b[1]);
    }
};