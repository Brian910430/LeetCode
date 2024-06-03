#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int i = 0;
        int j = 0;

        for (; i < s.length(); i++)
            if (s[i] == t[j])
                j++;
        return t.length() - j;
    }
};

int main()
{
    Solution solution;
    cout << solution.appendCharacters("coaching", "coding") << endl;
    cout << 11111 << endl;
    return 0;
}