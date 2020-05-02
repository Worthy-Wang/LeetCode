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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
题目：114. Flatten Binary Tree to Linked List
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/

begin: 13:27
end:  13:57
Time complexity: O(N) 
Space complexity: O(logN) ~ O(N)
*/
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root)
        {
            flatten(root->left);
            if (root->left)//将左子树形成的链表 插入到右子树之前
            {
                TreeNode *last_right = root->left;
                while (last_right->right) last_right = last_right->right;
                last_right->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            flatten(root->right);
        }
    }
};

int main()
{
    return 0;
}