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
题目：128. Longest Consecutive Sequence
链接：https://leetcode-cn.com/problems/longest-consecutive-sequence/

begin: 14:54
end:  15:53
Time complexity: O(N)
Space complexity: O(N)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_map<int, bool> used;
        for (auto& e: nums)
            used[e] = false;
        
        int maxLen = 0;
        int len = 0;
        for (auto& e: used)
        {
            if (e.second == true)
                continue;
            
            len = 0;
            for (int j = e.first; used.find(j)!= used.end(); j++)
            {   
                len ++;
                used[j] = true;
            }
            maxLen = std::max(maxLen, len);
        }

        return maxLen;
    }
};



int main()
{
    return 0;
}