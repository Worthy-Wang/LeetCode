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
题目：2. Add Two Numbers
链接：https://leetcode-cn.com/problems/add-two-numbers/

begin: 9:49
end:  10:50
Time complexity: O(m + n) 
Space complexity: O (1)
*/

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(-1);
        ListNode *tail = head;
        int carry = 0;
        int sum = 0;
        while (l1 || l2 || carry)
        {
            sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            carry = (sum>=10) ? 1: 0;
            ListNode *newNode = new ListNode(sum % 10);
            tail->next = newNode;
            tail = newNode;

            l1? l1 = l1->next : l1;
            l2? l2 = l2->next : l2;
        }
        return head->next;
    }
};

int main()
{
    return 0;
}