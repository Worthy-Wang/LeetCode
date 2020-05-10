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
题目：56. Merge Intervals
链接：https://leetcode-cn.com/problems/merge-intervals/

begin: 17:25
end:  17:49
Time complexity: O(NlogN) 
Space complexity: O(1)
*/
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        if (intervals.empty())
            return ans;
        sort(intervals.begin(), intervals.end());
        int Min = intervals[0][0], Max = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++ )
        {
            //不合并
            if (intervals[i][0] > Max)
            {
                ans.push_back(vector<int>{Min,Max});
                Min = intervals[i][0];
                Max = intervals[i][1];
            }
            else//合并
                Max = max(Max, intervals[i][1]);
        }
        ans.push_back(vector<int>{Min, Max});
        return ans;
    }
};

int main()
{
    return 0;
}