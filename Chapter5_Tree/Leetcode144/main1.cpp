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
题目：144. Binary Tree Preorder Traversal
链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/

begin: 9:43
end:  9:48
Time complexity: O(N) 
Space complexity: O(N)
*/
class Solution
{
public:
    void preTraverse(TreeNode* root)
    {
        if (root)
        {
            ans.push_back(root->val);
            preTraverse(root->left);
            preTraverse(root->right);
        }
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        preTraverse(root);
        return ans;
    }
private:
    vector<int> ans;
};


int main()
{
    return 0;
}