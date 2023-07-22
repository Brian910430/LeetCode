#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        for (int i = 0, j = s.length() - 1; i < j;)
        {
            if (isVowel(s[i]) && isVowel(s[j]))
                swap(s[i++], s[j--]);
            if (!isVowel(s[i]))
                i++;
            if (!isVowel(s[j]))
                j--;
        }
        return s;
    }

private:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};