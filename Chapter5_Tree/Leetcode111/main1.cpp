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

begin: 22:12
end:  22:23
Time complexity: O(N)
Space complexity: O(N)
*/
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        //BFS寻找叶子节点
        if (!root)
            return 0;
        queue<TreeNode*> cur, next;
        cur.push(root);
        int level = 1;
        while (!cur.empty())
        {
            while (!cur.empty())
            {
                TreeNode *node = cur.front();
                cur.pop();
                if (!node->left && !node->right)
                    return level;
                if (node->left)
                    next.push(node->left);
                if (node->right)
                    next.push(node->right);
            }
            level++;
            swap(cur, next);
        }
        return level;
    }
};


int main()
{
    return 0;
}