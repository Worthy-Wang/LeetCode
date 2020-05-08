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
#include <queue>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
题目：39. Combination Sum
链接：https://leetcode-cn.com/problems/combination-sum/

begin: 20:03
end:  20:24
Time complexity: O() 
Space complexity: 
*/
class Solution
{
    vector<vector<int>> ans;

public:
    void DFS(vector<int> &candidates, int target, vector<int> &path, int step)
    {
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }

        for (int i = step; i < candidates.size(); i++)
        {
            if (target < candidates[i])
                return; //剪枝
            path.push_back(candidates[i]);
            DFS(candidates, target - candidates[i], path, i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end(), std::less<int>());
        vector<int> path;
        DFS(candidates, target, path, 0);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> vec{2, 3, 6, 7};
    s.combinationSum(vec, 7);
    return 0;
}