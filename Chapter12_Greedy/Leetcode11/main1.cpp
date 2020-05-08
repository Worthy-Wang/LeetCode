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
#include <queue>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
题目：11. Container With Most Water
链接：https://leetcode-cn.com/problems/container-with-most-water/

begin: 18:00
end:  18:32
Time complexity: O(N)
Space complexity: O(1)
*/
//双指针法
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size()-1;
        int max_area = 0;
        while (l < r)
        {
            int area = (r - l) * min(height[l], height[r]);
            if (area > max_area)
                max_area = area;
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return max_area;
    }
};

int main()
{
    return 0;
}