#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
using namespace std;

/*
题目：16. 3Sum Closest
链接：https://leetcode-cn.com/problems/3sum-closest/

begin: 8:15
end:  8:53
Time complexity: O(n*n)
Space complexity: O(1)
*/
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        if (nums.size() <= 3)
        {
            int sum = 0;
            for (auto &e : nums)
                sum += e;
            return sum;
        }

        sort(nums.begin(), nums.end());
        int cloest = fabs((nums[0] + nums[1] + nums[2]) - target);
        int ans = nums[0] + nums[1] + nums[2];
        for (int k = 0; k < nums.size(); k++)
        {
            if (k > 0 && nums[k] == nums[k - 1])
                continue;
            int i = k + 1;
            int j = nums.size() - 1;
            int sum;

            while (i < j)
            {
                sum = nums[k] + nums[i] + nums[j];
                if (cloest > fabs(sum-target))
                {
                    cloest = fabs(sum - target);
                    ans = sum;
                }

                if (sum == target)
                    return target;
                else if (sum < target)
                {
                    i++;
                    while (i < j && nums[i] == nums[i - 1])
                        i++;
                }
                else
                {
                    j--;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums{-1, 2, 1, -4};
    Solution s;
    cout << s.threeSumClosest(nums, 1) << endl;
    return 0;
}