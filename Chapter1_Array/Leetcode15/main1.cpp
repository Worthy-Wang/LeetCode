#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

/*
题目：15. 3Sum
链接：https://leetcode-cn.com/problems/3sum/

begin: 16:42
end:  17:24
Time complexity: O(n*n) 
Space complexity: O(1) 此处的ans并不算作复杂度
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        if (nums.size() < 3)
            return ans;
        sort(nums.begin(), nums.end());
        if (nums[0] > 0)
            return ans;

        for (int k = 0; k < nums.size(); k++)
        {
            if (k>0 && nums[k]==nums[k-1])
                continue;

            int i = k + 1;
            int j = nums.size() - 1;
            while (i < j)
            {
                if (nums[k] + nums[i] + nums[j] == 0)
                {
                    ans.push_back(vector<int>{nums[k], nums[i], nums[j]});
                    i++;
                    while (i < j && nums[i]==nums[i-1]) i++;
                }
                else if (nums[k] + nums[i] + nums[j] > 0)
                    j--;
                else
                    i++;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> vec{-1, 0, 1, 2, -1, -4};
    Solution s;
    s.threeSum(vec);
    return 0;
}