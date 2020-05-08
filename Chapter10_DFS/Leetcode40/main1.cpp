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
题目：40. Combination Sum II
链接：https://leetcode-cn.com/problems/combination-sum-ii/

begin: 21:12
end:  21:19
Time complexity: O(N!) 
Space complexity: O(N)
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
            if (i > step && candidates[i] == candidates[i - 1])
                continue; //剪枝
            path.push_back(candidates[i]);
            DFS(candidates, target - candidates[i], path, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end(), std::less<int>());
        vector<int> path;
        DFS(candidates, target, path, 0);
        return ans;
    }
};

int main()
{

    return 0;
}