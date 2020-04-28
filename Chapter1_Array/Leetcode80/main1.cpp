#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

/*
题目：80. Remove Duplicates from Sorted Array II
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/

begin: 10:23
end:  10:31
Time complexity: O(N)
Space complexity: O(1)
*/
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums.size();
        int index = 1;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[index] != nums[i])
                nums[++index] = nums[i];
            else if (nums[index] == nums[i] && nums[index-1] != nums[index])
                nums[++index] = nums[i];
            else
                continue;
        }
        return index + 1;
    }
};



int main()
{
    vector<int> vec{1,1,2};
    Solution s;
    cout << s.removeDuplicates(vec) << endl;
    return 0;
}