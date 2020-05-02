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
题目：107. Binary Tree Level Order Traversal II
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/

begin: 11:26
end:  11:31
Time complexity: O(N) 
Space complexity: O(1)
*/
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans;
        stack<vector<int>> ans2;
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
            ans2.push(temp);
            swap(cur, next);
        }

        while (!ans2.empty())
        {
            ans.push_back(ans2.top());
            ans2.pop();
        }
        return ans;
    }
};

int main()
{
    return 0;
}