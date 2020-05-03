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
题目：116. Populating Next Right Pointers in Each Node
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/

begin: 10:32
end:  10:40
Time complexity: O(N) 
Space complexity: O(1) //题目中说明了递归不算做额外空间
*/
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;
        Node* head = new Node(-1);
        Node* tail = head;
        for (auto cur = root; cur; cur = cur->next)
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