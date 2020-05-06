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

begin: 14:12
end:  14:22
Time complexity: O(logN) 
Space complexity: O(1)
*/
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return std::distance(nums.begin(), Lower_bound(nums.begin(), nums.end(), target));
    }

    template <typename Iterator>
    Iterator Lower_bound(Iterator first, Iterator last, int target)
    {
        while (first < last)
        {
            auto mid = first + std::distance(first, last) / 2;
            if (*mid == target)
                return mid;
            else if (*mid < target)
                first = mid + 1;
            else 
                last = mid;
        }
        return first;
    }
};

int main()
{
    return 0;
}