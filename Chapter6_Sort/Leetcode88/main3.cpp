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

begin: 14:37
end:  14:41
Time complexity: O(N + M)  
Space complexity: O(1)
*/

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int cur = m + n -1;
        int i = m - 1;
        int j = n - 1;
        while (i >= 0 && j >= 0)
            nums1[i] > nums2[j] ? nums1[cur--] = nums1[i--] : nums1[cur--] = nums2[j--];
        while (j >= 0)
            nums1[cur--] = nums2[j--];
    }
};

int main()
{
    return 0;
}