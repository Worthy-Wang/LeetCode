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
题目：35. Search Insert Position
链接：https://leetcode-cn.com/problems/search-insert-position/

begin: 14:02
end:  14:08
Time complexity: O(logN) 
Space complexity: O(1)
*/
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size()-1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] == target)
                return mid;
            else if (target < nums[mid])
                r = mid - 1;
            else 
                l = mid + 1;
        }
        return l;
    }
};

int main()
{
    return 0;
}