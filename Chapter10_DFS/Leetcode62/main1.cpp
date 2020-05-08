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

begin: 14:40
end:  15:31
Time complexity:  
Space complexity: O(N)
*/
//DFS对于大的矩阵会超时
class Solution
{
public:
    void DFS(const pair<int,int>& grid, int& ans, int m, int n)
    {
        if (grid.first == m-1 && grid.second == n - 1)
        {
            ans ++;
            return;
        }
        
        //向右
        if (grid.second != n-1)
            DFS(make_pair(grid.first, grid.second+1), ans, m, n);
        //向下
        if (grid.first != m - 1)
            DFS(make_pair(grid.first+1, grid.second), ans, m, n);
    }

    int uniquePaths(int m, int n)
    {
        int ans = 0;
        DFS(make_pair(0,0), ans, m, n);
        return ans;        
    }
};


int main()
{
    return 0;
}