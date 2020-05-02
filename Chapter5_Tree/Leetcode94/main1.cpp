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
题目：94. Binary Tree Inorder Traversal
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/

begin: 10:06
end:  10:07
Time complexity: O(N) 
Space complexity: O(N)
*/
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode*> stk;
        while (1)
        {
            //向左
            while (root)
            {
                stk.push(root);
                root = root->left;
            }
            
            //向右
            if (stk.empty())
                break;
            else
            {
                TreeNode* top = stk.top();
                ans.push_back(top->val);
                stk.pop();
                root = top->right;
            }
        }
        return ans;
    }

private:
    vector<int> ans;
};


int main()
{
    return 0;
}