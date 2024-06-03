#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *ans = nullptr;
        int max = INT_MIN;
        while (temp != nullptr)
        {
            if (temp->val > max)
            {
                max = temp->val;
                ans = temp;
            }
            temp = temp->next;
        }
        removeNodes(ans, ans->next);
        return ans;
    }

private:
    int removeNodes(ListNode *prev, ListNode *curr)
    {
        if (curr == nullptr)
            return INT_MIN;
        int num = removeNodes(curr, curr->next);
        if (curr->val < num)
            prev->next = curr->next;
        return num > curr->val ? num : curr->val;
    }
};