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

begin: 8:25
end:  8:55
Time complexity: O(N)
Space complexity: O(1)
*/
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        stack<TreeNode *> stk1;
        stack<TreeNode *> stk2;
        stk1.push(root);
        while (!stk1.empty())
        {
            vector<int> temp;
            while (!stk1.empty())
            {
                TreeNode *node = stk1.top();
                stk1.pop();
                temp.push_back(node->val);
                if (node->left)
                    stk2.push(node->left);
                if (node->right)
                    stk2.push(node->right);
            }
            if (!temp.empty())
                ans.push_back(temp);

            temp.clear();
            while (!stk2.empty())
            {
                TreeNode *node = stk2.top();
                stk2.pop();
                temp.push_back(node->val);
                if (node->right)
                    stk1.push(node->right);
                if (node->left)
                    stk1.push(node->left);
            }
            if (!temp.empty())
                ans.push_back(temp);
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