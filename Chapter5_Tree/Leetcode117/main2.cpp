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
#include <cctype>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/*
题目：117. Populating Next Right Pointers in Each Node II
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/

begin: 14:22
end:  15:08
Time complexity: O(N) 
Space complexity: O(1)  题目中说明了递归调用的栈空间可以不算额外的空间复杂度
*/

class Solution
{
public:
    //使用已经建立好的next指针, N-1层为N层赋值next指针
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;
        Node *head = new Node(-1);
        Node *tail = head;
        for (auto cur = root; cur ; cur = cur->next)
        {
            if (cur->left)
            {
                tail->next = cur->left;
                tail = cur->left;
            }
            if (cur->right)
            {
                tail->next = cur->right;
                tail = cur->right;
            }
        }
        connect(head->next);
        return root;
    }
};

int main()
{

    return 0;
}