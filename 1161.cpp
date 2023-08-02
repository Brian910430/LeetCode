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
    int maxLevelSum(TreeNode *root)
    {
        queue<TreeNode *> record;
        int ans;
        int num = INT_MIN;
        int level = 1;
        record.push(root);

        while (record.size())
        {
            int n = record.size();
            int temp = 0;
            for (int i = 0; i < n; i++)
            {
                TreeNode *now = record.front();
                record.pop();
                temp += now->val;
                if (now->left != nullptr)
                    record.push(now->left);
                if (now->right != nullptr)
                    record.push(now->right);
            }
            if (num < temp)
            {
                num = temp;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};