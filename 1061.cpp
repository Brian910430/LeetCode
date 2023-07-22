#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        int n, n1, n2;
        vector<int> map(26, INT_MAX);
        for (int i = 0; i < 26; i++)
            map[i] = i;
        for (int i = 0; i < s1.length(); i++)
        {
            n1 = s1[i] - 'a';
            n2 = s2[i] - 'a';
            while (n1 != map[n1])
                n1 = map[n1];
            while (n2 != map[n2])
                n2 = map[n2];
            if (n1 < n2)
                map[n2] = n1;
            else
                map[n1] = n2;
        }
        for (int i = 0; i < baseStr.length(); i++)
        {
            n = baseStr[i] - 'a';
            while (map[n] != n)
                n = map[n];
            baseStr[i] = n + 'a';
        }
        return baseStr;
    }
};

int main()
{
    Solution solution;
    string s1 = "parker";
    string s2 = "morris";
    string baseStr = "parser";
    cout << solution.smallestEquivalentString(s1, s2, baseStr) << endl;
    s1 = "hello";
    s2 = "world";
    baseStr = "hold";
    cout << solution.smallestEquivalentString(s1, s2, baseStr) << endl;
    s1 = "leetcode";
    s2 = "programs";
    baseStr = "sourcecode";
    cout << solution.smallestEquivalentString(s1, s2, baseStr) << endl;
    return 0;
}