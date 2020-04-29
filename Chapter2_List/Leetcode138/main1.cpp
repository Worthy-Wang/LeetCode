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
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/*
题目：138. Copy List with Random Pointer
链接：https://leetcode-cn.com/problems/copy-list-with-random-pointer/

begin: 8:23
end:  8:32
Time complexity: O(N) 
Space complexity: O(N)
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *dummy = new Node(-1);
        Node *tail = dummy;
        //深拷贝：重新开辟链表空间
        unordered_map<Node*, Node*> hashmap; // <旧节点，新节点>
        for (auto cur = head; cur; cur = cur->next)
        {
            Node *node = new Node(cur->val);
            hashmap[cur] = node;
            tail->next = node;
            tail = node;
        }        
        hashmap[NULL] = NULL;

        //赋值random
        for (auto p = head, q = dummy->next; p, q; p = p->next, q = q->next)
            q->random = hashmap[p->random];

        return dummy->next;
    }
};

int main()
{

    Solution s;
    return 0;
}