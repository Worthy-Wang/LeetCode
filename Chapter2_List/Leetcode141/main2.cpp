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
题目：141. Linked List Cycle
链接：https://leetcode-cn.com/problems/linked-list-cycle/

begin: 9:00
end:  9:08
Time complexity: O(N) 
Space complexity: O(1)
*/
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;
        ListNode *p = head;
        ListNode *q = head->next;
        while (q)
        {
            if (p == q)
                break;
            p = p->next;
            q = q->next;
            if (q) 
                q = q->next;
        }
        if (!q)
            return false;
        else
            return true;
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