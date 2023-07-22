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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        ListNode *n1 = list1, *n2 = list2;
        ListNode *ans = new ListNode();
        ListNode *n3 = ans;
        while (n1 != nullptr || n2 != nullptr)
        {
            if (n1 == nullptr)
            {
                n3->next = n2;
                break;
            }
            else if (n2 == nullptr)
            {
                n3->next = n1;
                break;
            }
            else
            {
                if (n1->val < n2->val)
                {
                    n3->next = n1;
                    n1 = n1->next;
                }
                else
                {
                    n3->next = n2;
                    n2 = n2->next;
                }
                n3 = n3->next;
            }
        }
        return ans->next;
    }
};