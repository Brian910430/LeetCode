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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *index = head;
        ListNode *ans = new ListNode(0);
        ListNode *now = ans;
        while (index != nullptr)
        {
            if (index->val < x)
            {
                now->next = new ListNode(index->val);
                now = now->next;
            }
            index = index->next;
        }
        index = head;
        while (index != nullptr)
        {
            if (index->val >= x)
            {
                now->next = new ListNode(index->val);
                now = now->next;
            }
            index = index->next;
        }
        return ans->next;
    }
};