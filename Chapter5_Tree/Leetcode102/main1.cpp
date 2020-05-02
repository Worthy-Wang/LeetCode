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
题目：102. Binary Tree Level Order Traversal
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

begin: 11:02
end:  11:15
Time complexity: O(N)
Space complexity: O(1)
*/
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> cur, next;
        cur.push(root);
        while (!cur.empty())
        {
            vector<int> temp;
            while (!cur.empty())
            {
                TreeNode *node = cur.front();
                temp.push_back(node->val);
                cur.pop();
                if (node->left)
                    next.push(node->left);
                if (node->right)
                    next.push(node->right);
            }
            ans.push_back(temp);
            swap(cur, next);
        }
        return ans;
    }
};

int main()
{
    return 0;
}