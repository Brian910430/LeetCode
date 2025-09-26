#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string sortVowels(string s)
    {
        vector<int> record = vector<int>();
        priority_queue<char, vector<char>, greater<char>> pq;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                pq.push(s[i]);
                record.push_back(i);
            }
        for (int i = 0; i < record.size(); i++)
        {
            s[record[i]] = pq.top();
            pq.pop();
        }
        return s;
    }
};