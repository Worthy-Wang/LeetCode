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
题目：108. Convert Sorted Array to Binary Search Tree
链接：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/

begin: 21:31
end:  21:50
Time complexity: O(N) 
Space complexity: O(logN)
*/

class Solution
{
public:
    TreeNode *build(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return NULL;
        int mid = (l + r) >> 1;
        int key = nums[mid];
        TreeNode* root = new TreeNode(key);
        root->left = build(nums, l, mid-1);
        root->right = build(nums, mid+1, r);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return build(nums, 0, nums.size() - 1);
    }
};

int main()
{
    return 0;
}