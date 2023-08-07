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
    vector<TreeNode *> generateTrees(int n)
    {
        return n ? treeGenerate(1, n) : vector<TreeNode *>();
    }

private:
    vector<TreeNode *> treeGenerate(int start, int end)
    {
        if (start > end)
            return {nullptr};

        vector<TreeNode *> allTree;
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> leftTree = treeGenerate(start, i - 1);
            vector<TreeNode *> rightTree = treeGenerate(i + 1, end);
            for (auto lTree : leftTree)
                for (auto rTree : rightTree)
                    allTree.push_back(new TreeNode(i, lTree, rTree));
        }
        return allTree;
    }
};