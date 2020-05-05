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
题目：147. Insertion Sort List
链接：https://leetcode-cn.com/problems/insertion-sort-list/

begin: 16:34
end:  17:32
Time complexity: O(N^2) 
Space complexity: O(1)
*/
class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *dummy = new ListNode(INT_MIN);
        for (auto cur = head; cur;)
        {
            auto pos = find_insert_pos(dummy, cur->val);
            auto temp = cur->next;
            cur->next = pos->next;
            pos->next = cur;
            cur = temp;
        }
        return dummy->next;
    }

    ListNode *find_insert_pos(ListNode *dummy, int key)
    {
        ListNode *pre = dummy;
        for (auto cur = dummy->next; cur && cur->val <= key; pre = cur, cur = cur->next)
            ;
        return pre;
    }
};

int main()
{
    return 0;
}