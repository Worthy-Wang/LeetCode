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
题目：54. Spiral Matrix
链接：https://leetcode-cn.com/problems/spiral-matrix/

begin: 10:29
end:  11:06
Time complexity: O(M * N) 
Space complexity: O(M * N)
*/
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        if (matrix.empty())
            return ans;

        int M = matrix.size();
        int N = matrix[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        int x = 0, y = 0;
        visited[x][y] = true;
        ans.push_back(matrix[x][y]);
        int cnt = 1;
        while (1)
        {
            //向右
            while (y != N - 1 && !visited[x][y + 1])
            {
                y++;
                visited[x][y] = true;
                ans.push_back(matrix[x][y]);
                cnt++;
            }
            //向下
            while (x != M - 1 && !visited[x + 1][y])
            {
                x++;
                visited[x][y] = true;
                ans.push_back(matrix[x][y]);
                cnt++;
            }
            //向左
            while (y != 0 && !visited[x][y-1])
            {
                y--;
                visited[x][y] = true;
                ans.push_back(matrix[x][y]);
                cnt++;
            }
            //向上
            while (x != 0 && !visited[x-1][y])
            {
                x--;
                visited[x][y] = true;
                ans.push_back(matrix[x][y]);
                cnt++;
            }
            if (cnt == M * N)
                break;
        }
        return ans;
    }
};

int main()
{
    return 0;
}