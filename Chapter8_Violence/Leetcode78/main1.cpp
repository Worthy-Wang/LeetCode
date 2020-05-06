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
题目：78. Subsets
链接：https://leetcode-cn.com/problems/subsets/

begin: 14:03
end:  15:02
Time complexity: O(N^2) 
Space complexity: O(N)
*/
class Solution
{
    vector<vector<int>> ans;
public:
    void DFS(vector<int> &nums, int step, vector<int> &path)
    {
        ans.push_back(path);
        for (int i = step; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            DFS(nums, i + 1, path);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> path;
        DFS(nums, 0, path);
        return ans;
    }
};

int main()
{
    return 0;
}