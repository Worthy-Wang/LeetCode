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
题目：145. Binary Tree Postorder Traversal
链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/

begin: 10:50
end:  10:58
Time complexity: O(N) 
Space complexity: O(N)
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        stk1.push(root);
        while (!stk1.empty())
        {
            TreeNode *node = stk1.top();
            stk1.pop();
            stk2.push(node);
            if (node->left) stk1.push(node->left);
            if (node->right) stk1.push(node->right);
        }

        while (!stk2.empty())
        {
            ans.push_back(stk2.top()->val);
            stk2.pop();
        }
        return ans;
    }
};

int main()
{
    return 0;
}