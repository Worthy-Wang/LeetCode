#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

/*
题目：81. Search in Rotated Sorted Array II
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/

begin: 13:16
end:  13:36
Time complexity: O(logn)
Space complexity: O(1)
*/
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (nums[mid] == target)
                return true;
            else if (nums[l] < nums[mid]) //mid落在左边有序区
            {
                if (nums[l] <= target && target <= nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else if (nums[l] == nums[mid]) //不能确定是否在左边有序区还是在右边有序区
            {
                l++;
            }
            else //mid落在右边有序区
            {
                if (nums[mid] <= target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }

        }
        return false;
    }
};

int main()
{
    return 0;
}