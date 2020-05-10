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
题目：118. Pascal's Triangle
链接：https://leetcode-cn.com/problems/pascals-triangle/

begin: 9:42
end:  9:56
Time complexity: O(N^2) 
Space complexity: O(1)
*/
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> temp(i+1, 1);
            ans.push_back(temp);
            for (int j = 0; j <= i; j++)
                if (i > 0 && j > 0 && j < i)
                    ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        return ans;
    }
};

int main()
{
    return 0;
}