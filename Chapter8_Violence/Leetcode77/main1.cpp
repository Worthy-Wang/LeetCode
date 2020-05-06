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
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
题目：77. Combinations
链接：https://leetcode-cn.com/problems/combinations/

begin: 16:50
end:  17:17
Time complexity: O(N!) 
Space complexity: O(N)
*/
class Solution
{
    vector<vector<int>> ans;

public:
    void DFS(vector<int> &nums, int k, vector<int> &path, int step)
    {
        if (k == path.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = step; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            DFS(nums, k, path, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        if (n < k)
            return ans;
        vector<int> nums;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        vector<int> path;
        DFS(nums, k, path, 0);
        return ans;
    }
};

int main()
{
    return 0;
}