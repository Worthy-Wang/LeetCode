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

begin: 9:44
end:  11:30
Time complexity: O(N) 
Space complexity: O(1)
*/
class Solution
{
public:
    template<typename Iterator, typename Predicate>
    Iterator Partition(Iterator first, Iterator last, Predicate pred)
    {
        auto slow = first;
        for (auto fast = first; fast != last; fast++)
            if (pred(*fast))
                swap(*fast, *slow++);
        return slow;
    }

    void sortColors(vector<int> &nums)
    {
        Partition(Partition(nums.begin(), nums.end(), bind2nd(less_equal<int>(), 0)), \
        nums.end(), bind2nd(less_equal<int>(), 1));
    }
};

int main()
{
    Solution s;
    vector<int> nums{2,0,2,1,1,0};
    s.sortColors(nums);
    for (auto& e: nums)
        cout << e << endl;
    return 0;
}