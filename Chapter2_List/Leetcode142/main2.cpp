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
题目：142. Linked List Cycle II
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii/

begin: 9:20
end:  10:10
Time complexity: O(N) 
Space complexity: O(1)
*/
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                fast = head;
                while (fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};

int main()
{
    ListNode *l1 = new ListNode(3);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(0);
    ListNode *l4 = new ListNode(4);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l2;
    Solution s;
    s.detectCycle(l1);
    return 0;
}