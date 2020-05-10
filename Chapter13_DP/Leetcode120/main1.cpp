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
题目：120. Triangle
链接：https://leetcode-cn.com/problems/triangle/

begin: 8:46
end:  9:09
Time complexity: O(N^2)
Space complexity: O(1)
*/
//自低向上 动态规划
//dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + nums[i][j]
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle.size() == 0)
            return 0;
        
        int m = triangle.size();
        for (int i = m - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                triangle[i][j] = min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j];
        return triangle[0][0];
    }
};

int main()
{
    return 0;
}