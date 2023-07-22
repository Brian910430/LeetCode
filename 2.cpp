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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        auto now1 = l1;
        auto now2 = l2;
        int carry = 0;
        ListNode *ans = new ListNode(0);
        ListNode *now = ans;
        while (now1 != nullptr || now2 != nullptr || carry)
        {
            if (!now1 && !carry)
            {
                now->next = now2;
                break;
            }
            if (!now2 && !carry)
            {
                now->next = now1;
                break;
            }
            int digit1 = now1 ? now1->val : 0;
            int digit2 = now2 ? now2->val : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            sum %= 10;
            now->next = new ListNode(sum);
            now = now->next;
            if (now1)
                now1 = now1->next;
            if (now2)
                now2 = now2->next;
        }
        return ans->next;
    }
};