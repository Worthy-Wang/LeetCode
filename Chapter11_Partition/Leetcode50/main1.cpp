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
题目：50. Pow(x, n)
链接：https://leetcode-cn.com/problems/powx-n/

begin: 9:20
end:  10:03
Time complexity: O(logN) 
Space complexity: O(N)
*/
class Solution
{
public:
    double myPow(double x, int n)
    {
        long long N = n;
        if (N > 0)
            return Pow(x, N);
        return 1.0 / Pow(x, -N);
    }

    double Pow(double x, long long n)
    {
        if (n == 0)
            return 1;
        else if (n == 1)
            return x;
        else
        {
            double t = Pow(x, n / 2);
            return t * t * Pow(x, n % 2);
        }
    }
};

int main()
{
    Solution s;
    s.myPow(2, INT_MIN);
    return 0;
}