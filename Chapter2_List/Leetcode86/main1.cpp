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
题目：86. Partition List
链接：https://leetcode-cn.com/problems/partition-list/

begin: 13:46
end:  14:39
Time complexity: O(N)
Space complexity: O(1)
*/
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *left_head = new ListNode(-1);
        ListNode *right_head = new ListNode(-1);
        ListNode *left_cur = left_head;
        ListNode *right_cur = right_head;

        for (ListNode *cur = head; cur; cur = cur->next)
        {
            if (cur->val < x)
            {
                left_cur->next = cur;
                left_cur = cur;
            }else
            {
                right_cur->next = cur;
                right_cur = cur;
            }
        }
        left_cur->next = right_head->next;
        right_cur->next = NULL;
        return left_head->next;
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
    ListNode *head = s.partition(l1, 3);
    while (head)
    {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}