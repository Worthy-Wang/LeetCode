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
题目：148. Sort List
链接：https://leetcode-cn.com/problems/sort-list/

begin: 17:33
end:  18:38
Time complexity: O(N*logN) 
Space complexity: O(N)
*/
class Solution
{
public:
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        while (l1 && l2)
            l1->val < l2->val ? (tail->next = l1, tail = l1, l1 = l1->next) : (tail->next = l2, tail = l2, l2 = l2->next);
        tail->next = !l1 ? l2 : l1;
        return dummy.next;
    }

    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rhead = slow->next;
        slow->next = NULL;

        ListNode* l = sortList(head);
        ListNode* r = sortList(rhead);
        return merge(l, r); 
    }
};

int main()
{
    ListNode *l1 = new ListNode(4);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(1);
    ListNode *l4 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    Solution s;
    s.sortList(l1);
    return 0;
}