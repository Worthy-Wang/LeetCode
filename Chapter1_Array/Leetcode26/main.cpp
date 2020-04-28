#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
题目：26. Remove Duplicates from Sorted Array
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/

10:00 begin  10:07 end
Time complexity: O(N)
Space complexity: O(1)
*/
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int i = 0, j = 1;
        for (int k = 1; k < nums.size(); k++)
        {
            if (nums[j] != nums[i])
            {
                nums[++i] = nums[j++];
            }
            else
                j++;
        }
        return i + 1;
    }
};



int main()
{
    vector<int> vec{1,1,2};
    Solution s;
    cout << s.removeDuplicates(vec) << endl;
    return 0;
}