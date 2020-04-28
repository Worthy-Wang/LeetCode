#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

/*
题目：33. Search in Rotated Sorted Array
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array/

begin: 10:55
end:  11:19
Time complexity: O(logn)
Space complexity: O(1)
*/
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (nums[mid] == target)
                return mid;
            else if (nums[l] <= nums[mid]) //mid落在左边有序区
            {
                if (nums[l] <= target && target <= nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else //mid落在右边有序区
            {
                if (nums[mid] <= target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}