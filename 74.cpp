#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int left = 0;
        int right = matrix.size() - 1;
        int row;

        while (left < right)
        {
            int mid = (left + right + 1) / 2;
            if (matrix[mid][0] < target)
                left = mid;
            else if (matrix[mid][0] > target)
                right = mid - 1;
            else
            {
                left = mid;
                break;
            }
        }
        row = left;
        left = 0;
        right = matrix[0].size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (matrix[row][mid] < target)
                left = mid + 1;
            else if (matrix[row][mid] > target)
                right = mid - 1;
            else
                return true;
        }
        return false;
    }
};