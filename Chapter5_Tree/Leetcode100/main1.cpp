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
题目：100. Same Tree
链接：https://leetcode-cn.com/problems/same-tree/

begin: 9:11
end:  9:45
Time complexity: O(N)
Space complexity: 最优情况平衡二叉树O(logN) , 最差情况单链表O(N)
*/
class Solution
{
    bool flag;

public:
    void preTraverse(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
        {
            return;
        }
        else if (p && q)
        {
            if (p->val != q->val)
            {
                flag = false;
                return;
            }
            preTraverse(p->left, q->left);
            preTraverse(p->right, q->right);
        }
        else
            flag = false;
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        flag = true;
        preTraverse(p, q);
        return flag;
    }
};

int main()
{
    TreeNode* root1 = new TreeNode(10);
    TreeNode* left1 = new TreeNode(5);
    TreeNode* right1 = new TreeNode(15);

    TreeNode* root2 = new TreeNode(10);
    TreeNode* left2 = new TreeNode(5);
    TreeNode* right2 = new TreeNode(15);

    root1->left = left1;
    root1->right = right1;

    root2->left = left2;
    left2->right = right2;

    Solution s;
    s.isSameTree(root1, root2);
    return 0;
}