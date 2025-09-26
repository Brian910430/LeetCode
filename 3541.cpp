#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFreqSum(string s)
    {
        unordered_map<char, int> consonant = unordered_map<char, int>();
        unordered_map<char, int> vowel = unordered_map<char, int>();
        int vowelMax = 0;
        int consMax = 0;

        for (auto c : s)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowel[c]++;
            else
                consonant[c]++;
        }
        for (auto i : vowel)
            vowelMax = max(vowelMax, i.second);
        for (auto i : consonant)
            consMax = max(consMax, i.second);
        return vowelMax + consMax;
    }
};