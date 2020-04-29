#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <climits>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
题目：24. Swap Nodes in Pairs
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs/

begin: 16：31
end:  17:18
Time complexity: O(N)
Space complexity: O(1)
*/
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head)
            return NULL;
        if (!head->next)
            return head;

        ListNode *p = head;
        ListNode *q = p->next;
        ListNode *Head = new ListNode(-1);
        ListNode *prev = Head;
        while (p && q)
        {
            swap(p, q);
            q->next = p->next;
            p->next = q;
            prev->next = p;

            if (q->next && q->next->next)
            {
                prev = q;
                p = p->next->next;
                q = q->next->next;
            }else
                break;
        }        
        return Head->next;
    }
};

int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(4);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(2);
    ListNode *l5 = new ListNode(5);
    ListNode *l6 = new ListNode(2);
    l1->next = l2;
    l2->next = l3;
    swap(l1, l2);
    Solution s;
    return 0;
}