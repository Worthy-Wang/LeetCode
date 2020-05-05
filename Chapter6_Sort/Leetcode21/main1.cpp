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
题目：21. Merge Two Sorted Lists
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists/

begin: 14:42
end:  14:50
Time complexity: O(M + N) 
Space complexity: O(1)
*/
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(-1);
        ListNode *tail = head;
        while (l1 || l2)
        {
            if (l1 && l2)
                l1->val < l2->val ? (tail->next = l1, tail = l1, l1=l1->next) : (tail->next = l2, tail = l2, l2=l2->next);
            else
            {
                !l1 ? tail->next = l2 : tail->next = l1; 
                break;
            }
        }
        return head->next;
    }
};

int main()
{
    return 0;
}