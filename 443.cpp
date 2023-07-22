#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        if (chars.size() == 0)
            return 0;
        int length = 1;
        int number = 0;
        char now = 0;
        bool flag = false;

        for (int i = 0; i < chars.size(); i++)
        {
            if (chars[i] != now)
            {
                if (length != 1)
                {
                    string str = to_string(length);
                    for (int j = 0; j < str.size(); j++)
                        chars[number++] = str[j];
                }
                length = 1;
                now = chars[i];
                chars[number++] = now;
            }
            else
                length++;
        }
        if (length != 1)
        {
            string str = to_string(length);
            for (int j = 0; j < str.size(); j++)
                chars[number++] = str[j];
        }
        return number;
    }
};