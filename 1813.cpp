#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areSentencesSimilar(string s1, string s2)
    {
        if (s1.length() < s2.length())
            return areSentencesSimilar(s2, s1);
        int index1 = 0;
        int index2 = 0;
        int rindex1 = s1.length() - 1;
        int rindex2 = s2.length() - 1;

        while (1)
        {
            int i, j;
            for (i = 0; index1 + i < s1.length() && s1[index1 + i] != ' '; i++)
                ;
            for (j = 0; index2 + j < s2.length() && s2[index2 + j] != ' '; j++)
                ;
            if (s1.substr(index1, i) != s2.substr(index2, j))
                break;
            index1 += i + 1;
            index2 += j + 1;
            if (index2 >= s2.length())
                return true;
        }

        while (1)
        {
            int i, j;
            for (i = 0; rindex1 - i >= index1 && s1[rindex1 - i] != ' '; i++)
                ;
            for (j = 0; rindex2 - j >= index2 && s2[rindex2 - j] != ' '; j++)
                ;
            if (s1.substr(rindex1 - i + 1, i) != s2.substr(rindex2 - j + 1, j))
                break;
            rindex1 -= i + 1;
            rindex2 -= j + 1;
            if (rindex2 < index2)
                return true;
        }
        return false;
    }
};