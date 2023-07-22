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
    int findMaxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(findMaxDepth(root->left), findMaxDepth(root->right));
    }

    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        TreeNode *now;
        long long val;
        queue<pair<TreeNode *, long long>> q;
        vector<long long> comp(findMaxDepth(root), 0);
        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            now = q.front().first;
            val = q.front().second;
            q.pop();
            comp[val] += now->val;
            if (now->left)
                q.push(make_pair(now->left, val + 1));
            if (now->right)
                q.push(make_pair(now->right, val + 1));
        }
        sort(comp.begin(), comp.end());
        return comp.size() >= k ? comp[comp.size() - k] : -1;
    }
};