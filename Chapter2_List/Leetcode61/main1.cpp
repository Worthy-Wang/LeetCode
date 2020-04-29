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
题目：61. Rotate List
链接：https://leetcode-cn.com/problems/rotate-list/

begin: 15:49
end:  16：09
Time complexity: O(N) 
Space complexity: O(1)
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return NULL;
        
        int len = 1;
        auto cur = head;
        for (; cur->next; cur = cur->next) len++;
        cur->next = head;//成环
        k = k % len;
        int nextDistance = len - k;
        for (int i = 1; i <= nextDistance; i++)
            cur = cur->next;
        
        ListNode *Head = cur->next;
        cur->next = NULL;
        return Head;
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