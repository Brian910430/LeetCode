#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        for (int i = 0; i < flowerbed.size(); i++)
            if (!flowerbed[i] && (i == 0 || !flowerbed[i - 1]) && (i == flowerbed.size() - 1 || !flowerbed[i + 1]))
            {
                if (n == 1)
                    return true;
                flowerbed[i] = 1;
                n--;
            }
        return n <= 0;
    }
};