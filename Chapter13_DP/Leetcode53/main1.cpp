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
题目：53. Maximum Subarray
链接：https://leetcode-cn.com/problems/maximum-subarray/

begin: 9:13
end:  9:21
Time complexity: O(N)
Space complexity: O(N)
*/
//动态规划 dp[i] = max(dp[i-1] + nums[i], nums[i])
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int max_sum = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            max_sum = max(dp[i], max_sum);
        }
        return max_sum;
    }
};


int main()
{
    return 0;
}