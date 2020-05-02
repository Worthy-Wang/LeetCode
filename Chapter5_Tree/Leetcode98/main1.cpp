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
题目：98. Validate Binary Search Tree
链接：https://leetcode-cn.com/problems/validate-binary-search-tree/

begin: 21:22 
end:  21:29
Time complexity: O(N) 
Space complexity: O(N)
*/
class Solution
{
    vector<int> ans;
public:
    void inTraverse(TreeNode* root)
    {
        if (root)
        {
            inTraverse(root->left);
            ans.push_back(root->val);
            inTraverse(root->right);
        }
    }

    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;
        inTraverse(root);
        for (int i = 1; i < ans.size(); i++)
            if (ans[i-1] >= ans[i])
                return false;
        return true;
    }
};

int main()
{
    return 0;
}