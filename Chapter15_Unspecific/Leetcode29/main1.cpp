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
题目：29. Divide Two Integers
链接：https://leetcode-cn.com/problems/divide-two-integers/

begin: 14:21
end:  
Time complexity: 
Space complexity: 
*/
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        long long x = dividend > 0 ? dividend : -(long long)dividend;
        long long y = divisor > 0 ? divisor : -(long long)divisor;
        long long res = 0;
        for (int i = 31; i >= 0; i--)
        {
            if ((x >> i) >= y)
            {
                x -= (1 << i) * y;
                res += (1 << i);
            }
        }
        res =  (dividend ^ divisor) >= 0 ? res : -res;
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.divide(-2147483648, 1) << endl;
    return 0;
}