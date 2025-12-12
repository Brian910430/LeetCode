#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findLexSmallestString(string s, int a, int b)
    {
        unordered_set<string> seen = unordered_set<string>();
        queue<string> q = queue<string>();
        string smallest = s;
        string now = "";
        string new1 = "";
        string new2 = "";

        q.push(s);
        seen.insert(s);
        while (q.size())
        {
            now = q.front();
            q.pop();
            if (now < smallest)
                smallest = now;
            new1 = now;
            for (int i = 1; i < now.length(); i += 2)
                new1[i] = (new1[i] - '0' + a) % 10 + '0';
            new2 = now.substr(now.length() - b, b) + now.substr(0, now.length() - b);
            if (seen.count(new1) == 0)
            {
                q.push(new1);
                seen.insert(new1);
            }
            if (seen.count(new2) == 0)
            {
                q.push(new2);
                seen.insert(new2);
            }
        }
        return smallest;
    }
};