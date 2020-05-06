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
题目：90. Subsets II
链接：https://leetcode-cn.com/problems/subsets-ii/

begin: 15:03
end:  15:09
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
            if(i > step && nums[i] == nums[i-1])
                continue;
            path.push_back(nums[i]);
            DFS(nums, i + 1, path);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), std::less<int>());
        vector<int> path;
        DFS(nums, 0, path);
        return ans;
    }
};

int main()
{
    return 0;
}