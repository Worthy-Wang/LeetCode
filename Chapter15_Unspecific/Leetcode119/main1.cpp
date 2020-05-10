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
题目：119. Pascal's Triangle II
链接：https://leetcode-cn.com/problems/pascals-triangle-ii/

begin: 9:57
end:  10:07
Time complexity: O(N^2) 
Space complexity: O(N^2)
*/
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> ans;
        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> temp(i + 1, 1);
            ans.push_back(temp);
            for (int j = 0; j <= i; j++)
                if (i > 0 && j > 0 && j < i)
                    ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        return ans[rowIndex];
    }
};

int main()
{
    return 0;
}