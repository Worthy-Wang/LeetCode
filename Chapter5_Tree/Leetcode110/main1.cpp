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
题目：110. Balanced Binary Tree
链接：https://leetcode-cn.com/problems/balanced-binary-tree/

begin: 13:09
end:  13:21
Time complexity: O(NlogN)
Space complexity: O(N)
*/


class Solution {
public:
    int height(TreeNode* root)
    {
        return root ? max(height(root->left), height(root->right)) + 1 : 0;
    }

    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};


int main()
{
    return 0;
}