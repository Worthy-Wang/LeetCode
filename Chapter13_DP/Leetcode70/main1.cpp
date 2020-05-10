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
题目：70. Climbing Stairs
链接：https://leetcode-cn.com/problems/climbing-stairs/

begin: 10:57
end:  11:07
Time complexity: O(N)
Space complexity: O(N)
*/
//动态规划 逆推
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};

int main()
{
    return 0;
}