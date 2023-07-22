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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *temp = even;
        while (odd && even)
        {
            if (odd)
            {
                odd->next = (even == nullptr) ? nullptr : even->next;
                odd = (even->next == nullptr) ? odd : even->next;
            }
            if (even)
            {
                even->next = odd->next;
                even = odd->next;
            }
        }
        odd->next = temp;
        return head;
    }
};