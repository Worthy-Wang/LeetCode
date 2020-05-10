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
题目：64. Minimum Path Sum
链接：https://leetcode-cn.com/problems/minimum-path-sum/

begin: 9:25
end:  9:54
Time complexity: O(N^2)
Space complexity: O(N^2)
*/
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (i + 1 < m)
                    dp[i+1][j] = min(dp[i][j] + grid[i+1][j] , dp[i+1][j]);
                if (j + 1 < n)
                    dp[i][j+1] = min(dp[i][j] + grid[i][j+1], dp[i][j+1]);
            }
        return dp[m-1][n-1];
    }
};

int main()
{
    return 0;
}