#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        char last = 'a';
        char start = 'a';

        for (int i = 0; i < sentence.length(); i++)
        {
            if (i > 0 && sentence[i - 1] == ' ')
            {
                start = sentence[i];
                if (start != last)
                    return false;
            }
            if (i + 1 == sentence.length() || sentence[i + 1] == ' ')
                last = sentence[i];
        }
        return last == sentence[0];
    }
};