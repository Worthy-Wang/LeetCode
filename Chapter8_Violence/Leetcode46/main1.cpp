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
题目：46. Permutations
链接：https://leetcode-cn.com/problems/permutations/

begin: 15:11
end:  15:40
Time complexity: O(N!)
Space complexity: O(N)
*/
class Solution
{
    vector<vector<int>> ans;
public:
    void DFS(vector<int>& nums, vector<int>& path)
    {
        if (path.size() == nums.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            auto it = find(path.begin(), path.end(), nums[i]);
            if (it == path.end())
            {
                path.push_back(nums[i]);
                DFS(nums, path);
                path.pop_back();        
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> path;
        DFS(nums, path);
        return ans;
    }
};

int main()
{
    return 0;
}