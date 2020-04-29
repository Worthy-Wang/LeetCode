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
题目：19. Remove Nth Node From End of List
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

begin: 16:10
end:  16:29
Time complexity: O(N)
Space complexity: O(1)
*/
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        //双指针法
        ListNode *p = head;
        ListNode *q = head;
        for (int i = 0; i < n; i++)
            q = q->next;
        if (!q)
            return head->next;

        while (q->next)
        {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        return head;
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
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    Solution s;
    return 0;
}