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
题目：111. Minimum Depth of Binary Tree
链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/

begin: 8:19
end:  8:52
Time complexity: O()
Space complexity: O()
*/
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
            
        if (!root->left && !root->right)//左右都没有
            return 1;
        else if (!root->left) //没有左
            return minDepth(root->right) + 1;
        else if (!root->right) // 没有右
            return minDepth(root->left) + 1;
        else //都有
            return std::min(minDepth(root->left), minDepth(root->right)) + 1;

    }
};

int main()
{
    return 0;
}