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

begin: 8:57
end:  9：14
Time complexity: O(N) 
Space complexity: O(logN) ~ O(N)
*/
class Solution
{
    bool flag;
public:
    void preTraverse(TreeNode* root, int num, int sum)
    {
        if (root)
        {
            num += root->val;
            if (!root->left && !root->right && num == sum)
                flag = true;
            preTraverse(root->left, num, sum);
            preTraverse(root->right, num, sum);
        }
    }

    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root)
            return false;
        flag = false;
        preTraverse(root, 0, sum);
        return flag;
    }
};

int main()
{
    return 0;
}