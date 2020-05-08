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
题目：69. Sqrt(x)
链接：https://leetcode-cn.com/problems/sqrtx/

begin: 10:05
end:  10:30
Time complexity: O(logN) 
Space complexity: O(1)
*/
class Solution
{
public:
    int mySqrt(int x)
    {
        long long X = x;
        long long l = 1, r = X;
        while (l <= r)
        {
            long long mid = (l + r) >> 1;
            if (mid * mid == X)
                return mid;
            else if (mid * mid < X)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r;
    }
};

int main()
{
    return 0;
}