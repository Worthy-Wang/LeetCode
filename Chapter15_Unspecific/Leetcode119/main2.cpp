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

begin: 10:15
end:  10:28
Time complexity: O(N^2) 
Space complexity: O(N)
*/
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans;
        for (int i = 0; i <= rowIndex; i++)
        {
            for (int j = i - 1; j >= 0; j--)
                if (j - 1 >= 0)
                    ans[j] += ans[j - 1];
            ans.push_back(1);
        }
        return ans;
    }
};

int main()
{
    return 0;
}