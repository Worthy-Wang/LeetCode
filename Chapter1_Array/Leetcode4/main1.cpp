#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

/*
题目：4. Median of Two Sorted Arrays
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/

begin: 13：46
end:  14: 03
Time complexity: O(M + N)
Space complexity: O(M + N)
*/
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> vec(nums1.size() + nums2.size());
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), vec.begin());
        size_t len = vec.size();
        if (len % 2 == 0)
        {
            return (double)(vec[len/2] + vec[len/2-1]) / 2;
        }
        else
        {
            return vec[len/2];
        }
    }
};

int main()
{
    return 0;
}