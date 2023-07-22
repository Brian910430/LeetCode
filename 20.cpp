#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string str)
    {
        int n = str.length();
        if (!n)
            return true;
        stack<char> s;
        s.push('0');
        unordered_map<char, char> m = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

        for (int i = 0; i < n; i++)
        {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{')
                s.push(str[i]);
            else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
            {
                char t = s.top();
                s.pop();
                if (str[i] != m[t])
                    return false;
            }
        }
        if (s.size() > 1)
            return false;
        else
            return true;
    }
};