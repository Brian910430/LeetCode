#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int index;
        int now;
        int ans = 0;
        for (index = 0; index < k; index++)
            ans += isVowel(s[index]);
        now = ans;
        for (int i = 0; index < s.length(); i++, index++)
        {
            now += isVowel(s[index]) - isVowel(s[i]);
            ans = max(ans, now);
        }
        return ans;
    }

private:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};