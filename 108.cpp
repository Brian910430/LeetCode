#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int n = nums.size();
        TreeNode *ans = buildTree(nums, -1, n);
        return ans;
    }

    TreeNode *buildTree(vector<int> &nums, int left, int right)
    {
        int mid = (left + right) / 2;
        if (mid == left || mid == right)
            return nullptr;
        TreeNode *re = new TreeNode(nums[mid], buildTree(nums, left, mid), buildTree(nums, mid, right));
        return re;
    }
};