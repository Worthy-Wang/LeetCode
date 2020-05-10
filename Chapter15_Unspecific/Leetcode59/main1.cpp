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
题目：59. Spiral Matrix II
链接：https://leetcode-cn.com/problems/spiral-matrix-ii/

begin: 13:12
end:  13:21
Time complexity: O(N^2)
Space complexity: O(N^2)
*/
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int x = 0, y = 0;
        ans[0][0] = 1;
        int cnt = 2;
        while (1)
        {
            //向右
            while (y != n - 1 && !ans[x][y + 1])
                ans[x][++y] = cnt++;
            //向下
            while (x != n - 1 && !ans[x + 1][y])
                ans[++x][y] = cnt++;
            //向左
            while (y != 0 && !ans[x][y - 1])
                ans[x][--y] = cnt++;
            //向上
            while (x != 0 && !ans[x - 1][y])
                ans[--x][y] = cnt++;
            if (cnt == n * n + 1)
                break;
        }
        return ans;
    }
};

int main()
{
    return 0;
}