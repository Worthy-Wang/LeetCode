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
题目：82. Remove Duplicates from Sorted List II
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/

begin: 15:00
end:  15:16
Time complexity: O(N) 
Space complexity: O(1)
*/

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        for (auto cur = head; cur; cur = cur->next)
        {
            bool flag = false;
            while (cur->next && cur->val == cur->next->val)
            {
                flag = true;
                cur = cur->next;
            }
            if (!flag)
            {
                tail->next = cur;
                tail = cur;
            }
        }
        tail->next = NULL;
        return dummy->next;
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