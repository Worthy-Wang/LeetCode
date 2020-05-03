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
题目：112. Path Sum
链接：https://leetcode-cn.com/problems/path-sum/

begin: 9:16
end:  9:34
Time complexity: O(N) 
Space complexity: O(logN) ~ O(N)
*/
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root)
            return false;
        if (!root->left && !root->right)
            return root->val == sum;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

int main()
{
    return 0;
}