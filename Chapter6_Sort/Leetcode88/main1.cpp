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
题目：88. Merge Sorted Array
链接：https://leetcode-cn.com/problems/merge-sorted-array/

begin: 11:42
end:  11:48
Time complexity:  O(N + M)
Space complexity: O(N + M)
*/

class Solution
{
public:
    template <typename inputIterator1, typename inputIterator2, typename outputIterator>
    outputIterator myMerge(inputIterator1 first1, inputIterator1 last1, inputIterator2 first2, inputIterator2 last2, outputIterator result)
    {
        while (1)
        {
            if (first1 == last1)
                return std::copy(first2, last2, result);
            if (first2 == last2)
                return std::copy(first1, last1, result);
            *result++ = (*first1 < *first2) ? *first1++ : *first2++;
        }
    }

    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> temp(m + n);
        myMerge(nums1.begin(), nums1.begin()+m, nums2.begin(), nums2.begin()+n, temp.begin());
        swap(temp, nums1);
    }
};

int main()
{
    return 0;
}