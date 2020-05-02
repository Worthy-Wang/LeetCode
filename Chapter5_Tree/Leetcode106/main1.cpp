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
题目：105. Construct Binary Tree from postorder and Inorder Traversal
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-postorder-and-inorder-traversal/

begin: 16:10
end:  16:16
Time complexity: O(N) 
Space complexity: O(1)
*/
class Solution
{
    int i;

public:
    TreeNode *build(vector<int> &postorder, vector<int> &inorder, int l, int r)
    {
        if (l > r)
            return NULL;
        int key = postorder[i++];
        TreeNode *root = new TreeNode(key);
        int mid = std::distance(inorder.begin(), std::find(inorder.begin(), inorder.end(), key));
        root->right = build(postorder, inorder, mid + 1, r);
        root->left = build(postorder, inorder, l, mid - 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        i = 0;
        std::reverse(postorder.begin(), postorder.end());
        return build(postorder, inorder, 0, inorder.size() - 1);
    }
};

int main()
{
    vector<int> postorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};
    Solution s;
    cout << s.buildTree(postorder, inorder)->val << endl;
    return 0;
}