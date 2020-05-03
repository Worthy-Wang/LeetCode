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
题目：113. Path Sum II
链接：https://leetcode-cn.com/problems/path-sum-ii/

begin: 10:10
end:  10:19
Time complexity: O(N)
Space complexity: O(logN) ~ O(N)
*/
class Solution
{
    vector<vector<int>> ans;

public:
    void DFS(TreeNode *root, int sum, vector<int>& temp)
    {
        if (!root)
            return;
        temp.push_back(root->val);

        if (!root->left && !root->right && root->val == sum)
            ans.push_back(temp);
        else
        {
            DFS(root->left, sum - root->val, temp);
            DFS(root->right, sum - root->val, temp);
        }
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<int> temp;
        DFS(root, sum, temp);
        return ans;
    }
};

int main()
{
    return 0;
}