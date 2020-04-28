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

/*
题目：18. 4Sum
链接：https://leetcode-cn.com/problems/4sum/

begin: 9:06
end:  9：37
Time complexity: O (n^3)
Space complexity: O(1)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4)
            return ans;
        
        sort(nums.begin(), nums.end());
        for (int m = 0; m < nums.size() - 3; m++)
        {
            for (int n = m + 1; n < nums.size() - 2; n++)
            {
                int i = n + 1;
                int j = nums.size() - 1;
                while (i < j)
                {
                    int sum = nums[m] + nums[n] + nums[i] + nums[j];
                    if (sum == target)
                    {
                        ans.push_back(vector<int>{nums[m],nums[n],nums[i],nums[j]});
                        i++;
                        j--;
                    }   
                    else if (sum < target)
                        i++;
                    else
                        j--;
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};



int main()
{
    return 0;
}