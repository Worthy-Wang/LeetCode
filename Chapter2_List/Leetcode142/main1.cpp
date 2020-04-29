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

begin: 9:10
end:  9:19
Time complexity: O(N) 
Space complexity: O(N)
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> visited;
        ListNode *p = head;
        while (p)
        {
            if (visited.find(p) != visited.end())
                return p;
            visited[p] = true;
            p = p->next;
        }
        return NULL;
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