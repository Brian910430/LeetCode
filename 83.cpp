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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return head;

        ListNode *now = nullptr;
        ListNode *next = head;
        unordered_map<int, int> existed;
        while (next != nullptr)
        {
            if (existed[next->val])
            {
                now->next = next->next;
                next = now->next;
            }
            else
            {
                existed[next->val] = 1;
                now = next;
                next = now->next;
            }
        }
        return head;
    }
};