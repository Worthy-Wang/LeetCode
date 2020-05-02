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
题目：105. Construct Binary Tree from Preorder and Inorder Traversal
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

begin: 15:11
end:  16:06
Time complexity: O(N) 
Space complexity: O(1)
*/
class Solution
{
    int i;
public:
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int l, int r)
    {
        if (l > r)
            return NULL;
        int key = preorder[i++];
        TreeNode *root = new TreeNode(key);
        int mid = std::distance(inorder.begin(), std::find(inorder.begin(), inorder.end(), key));
        root->left = build(preorder, inorder, l, mid - 1);
        root->right = build(preorder, inorder, mid + 1, r);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        i = 0;
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};

int main()
{
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};
    Solution s;
    cout << s.buildTree(preorder, inorder)->val << endl;
    return 0;
}