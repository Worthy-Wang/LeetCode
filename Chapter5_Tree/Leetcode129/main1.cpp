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
题目：129. Sum Root to Leaf Numbers
链接：https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/

begin: 10：41
end:  10:54
Time complexity: O(N) 
Space complexity: O(N)
*/
class Solution
{
    vector<int> ans;
public:
    void DFS(TreeNode* root, string& num)
    {
        if (!root)
            return;
        num += to_string(root->val);
        if (!root->left && !root->right)
            ans.push_back(stoi(num));
        else
        {
            DFS(root->left, num);
            DFS(root->right, num);
        }
        num.pop_back();
    }

    int sumNumbers(TreeNode *root)
    {
        string num;
        DFS(root, num);
        int sum = 0;
        for (auto& e: ans)
            sum += e;
        return sum;
    }
};


int main()
{
    return 0;
}