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
题目：92. Reverse Linked List II
链接：https://leetcode-cn.com/problems/reverse-linked-list-ii/

begin: 10:54
end:  13:39
Time complexity: O(N)
Space complexity: O(1)
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *Head = new ListNode(-1);
        ListNode *prev = Head;
        prev->next = head;
        for (int i = 1; i < m; i ++)
            prev = prev->next;
        ListNode *cur = prev->next;
        ListNode *tail = cur;
        prev->next = NULL;
        //以prev为开始进行尾插法
        ListNode *pnext = NULL;
        for (int i = m; i <= n; i++)
        {
            pnext = cur->next;
            cur->next = prev->next;
            prev->next = cur;
            cur = pnext;
        }
        //此时tail已经作为尾节点
        tail->next = pnext;
        return Head->next;
    }
};


int main()
{
    return 0;
}