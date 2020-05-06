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

begin: 13:38
end:  14:00
Time complexity: O(log(M*N)) 
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
        int l = 0;
        int r = M * N;
        while ( l < r)
        {
            int mid = l + (r - l) / 2;
            int val = matrix[mid / N][mid % N];
            if (val == target)
                return true;
            else if (val < target)
                l = mid + 1;
            else
                r = mid;
        }
        return false;
    }   
};


int main()
{
    vector<vector<int>> matrix{{1,1}};
    Solution s;
    s.searchMatrix(matrix, 13);
    return 0;
}