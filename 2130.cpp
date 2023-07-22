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
    int pairSum(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *reverse = nullptr;
        int ans = 0;

        while (fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        while (slow != nullptr)
        {
            ListNode *temp = slow->next;
            slow->next = reverse;
            reverse = slow;
            slow = temp;
        }

        while (head != nullptr && reverse != nullptr)
        {
            ans = max(head->val + reverse->val, ans);
            head = head->next;
            reverse = reverse->next;
        }
        return ans;
    }
};