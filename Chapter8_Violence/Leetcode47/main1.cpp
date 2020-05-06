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
题目：47. Permutations II
链接：https://leetcode-cn.com/problems/permutations-ii/

begin: 15:42
end:  16:47
Time complexity: O(N!)
Space complexity: O(N)
*/
class Solution
{
    vector<vector<int>> ans;

public:
    void DFS(vector<int> &nums, vector<int> &path, vector<bool>& visited)
    {
        if (path.size() == nums.size())
        {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1])//剪枝
                continue;

            if (visited[i] == false)
            {
                visited[i] = true;
                path.push_back(nums[i]);
                DFS(nums, path, visited);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false); // <下标，是否访问过>
        vector<int> path;
        DFS(nums, path, visited);
        return ans;
    }
};

int main()
{
    return 0;
}