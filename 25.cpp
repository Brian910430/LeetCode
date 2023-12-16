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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k < 2)
            return head;
        ListNode *ans = new ListNode(0);
        ListNode *now = ans;
        ListNode *index = head;
        stack<ListNode *> record;

        while (index != nullptr)
        {
            while (record.size() < k)
            {
                if (index == nullptr)
                {
                    while (record.size() > 1)
                        record.pop();
                    now->next = record.top();
                    return ans->next;
                }
                record.push(index);
                index = index->next;
            }
            while (record.size())
            {
                now->next = record.top();
                record.pop();
                now = now->next;
            }
            now->next = nullptr;
        }
        return ans->next;
    }
};