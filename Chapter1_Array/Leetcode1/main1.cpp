#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

/*
题目：1. Two Sum
链接：https://leetcode-cn.com/problems/two-sum/

begin: 16:02
end:  16:40
Time complexity: O(N)
Space complexity: O(N)
*/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        if (nums.empty())
            return vector<int>();

        unordered_map<int, int> hashmap; //<值,下标>
        for (int i = 0; i < nums.size(); i++)
        {
            if (hashmap.find(target - nums[i]) != hashmap.end())
                return vector<int>{hashmap[target-nums[i]], i};
            hashmap[nums[i]] = i;
        }
        return vector<int>();
    }
};

int main()
{

    return 0;
}