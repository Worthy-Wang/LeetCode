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
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
题目：74. Search a 2D Matrix
链接：https://leetcode-cn.com/problems/search-a-2d-matrix/

begin: 13:32
end:  13:35
Time complexity: O(M + logN) 
Space complexity: O(1)
*/
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int M = matrix.size();
        int N = matrix[0].size();
        int i;
        for (i = 0; i < M; i++)
            if (target>= matrix[i][0] && target<= matrix[i][N-1])
                break;

        if (i == M)
            return false;
        auto it = lower_bound(matrix[i].begin(), matrix[i].end(), target);
        if (it == matrix[i].end())
            return false;
        return *it == target ? true : false;
    }
};


int main()
{
    return 0;
}