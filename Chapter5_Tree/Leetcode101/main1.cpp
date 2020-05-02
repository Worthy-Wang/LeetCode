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
题目：101. Symmetric Tree
链接：https://leetcode-cn.com/problems/symmetric-tree/

begin: 9:58
end:  10:28
Time complexity: O(N) 
Space complexity: O(logN)
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isSymmetric(root->left, root->right);       
    }

    bool isSymmetric(TreeNode* p, TreeNode* q) {
        if (!p && !q)//都不存在
            return true;
        else if (!p || !q)//有一个不存在
            return false;
        else //都存在
            return p->val==q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }
};


int main()
{   
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(2);
    TreeNode *node4 = new TreeNode(3);
    TreeNode *node5 = new TreeNode(4);
    TreeNode *node6 = new TreeNode(4);
    TreeNode *node7 = new TreeNode(3);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    Solution s;
    cout << s.isSymmetric(node1) << endl;   
    return 0;
}