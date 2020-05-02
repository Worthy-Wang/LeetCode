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

begin: 14:02
end:  14:20
Time complexity: O(N) 
Space complexity: O(N)
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;
        queue<Node *> cur, next;
        cur.push(root);
        while (!cur.empty())
        {
            Node *node = cur.front();
            cur.pop();
            Node *tail = node;
            if (tail->left)
                next.push(tail->left);
            if (tail->right)
                next.push(tail->right);
            while (!cur.empty())
            {
                Node *temp = cur.front();
                cur.pop();
                tail->next = temp;
                tail = temp;
                if (tail->left)
                    next.push(tail->left);
                if (tail->right)
                    next.push(tail->right);
            }
            swap(cur, next);
        }
        return root;
    }
};

int main()
{

    return 0;
}