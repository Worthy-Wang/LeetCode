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
题目：62. Unique Paths
链接：https://leetcode-cn.com/problems/unique-paths/

begin: 15:35
end:  15:48
Time complexity:  O(N^2)
Space complexity: O(N)
*/
//DP dp[i][j] = dp[i-1][j] + dp[i][j-1]
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m-1][n-1];
    }
};

int main()
{
    return 0;
}