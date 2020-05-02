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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
题目：103. Binary Tree Zigzag Level Order Traversal
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/

begin: 9:01
end:  9:09
Time complexity: O(N)
Space complexity: O(N)
*/
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        stack<TreeNode *> cur, next;
        bool left_to_right = true;
        cur.push(root);
        while (!cur.empty())
        {
            vector<int> temp;
            while (!cur.empty())
            {
                TreeNode *node = cur.top();
                cur.pop();
                temp.push_back(node->val);
                if (left_to_right)
                {
                    if (node->left)
                        next.push(node->left);
                    if (node->right)
                        next.push(node->right);
                }
                else
                {
                    if (node->right)
                        next.push(node->right);
                    if (node->left)
                        next.push(node->left);
                }
            }
            ans.push_back(temp);
            swap(cur, next);
            left_to_right = !left_to_right;
        }
        return ans;
    }
};

int main()
{
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(3);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(3);
    TreeNode *node5 = new TreeNode(3);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    Solution s;
    vector<vector<int>> ans = s.zigzagLevelOrder(node1);

    return 0;
}