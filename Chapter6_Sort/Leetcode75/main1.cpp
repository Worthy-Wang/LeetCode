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
题目：75. Sort Colors
链接：https://leetcode-cn.com/problems/sort-colors/

begin: 9:30
end:  9:41
Time complexity: O(N^2) 
Space complexity: O(1)
*/
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        vector<int> cnts(3);
        for (auto &e: nums)
            cnts[e]++;
        int k = 0;
        for (size_t i = 0; i < 3; i++)
            for (size_t j = cnts[i]; j > 0; j--)
                nums[k++] = i;
    }
};

int main()
{
    return 0;
}