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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
题目：109. Convert Sorted List to Binary Search Tree
链接：https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/

begin: 22:04
end:  22:10
Time complexity: O(N) 
Space complexity: O(N)
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
        TreeNode *root = new TreeNode(key);
        root->left = build(nums, l, mid - 1);
        root->right = build(nums, mid + 1, r);
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        vector<int> nums;
        while (head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        return build(nums, 0, nums.size()-1);
    }
};

int main()
{
    return 0;
}