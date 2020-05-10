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
#include <sstream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
题目：7. Reverse Integer
链接：https://leetcode-cn.com/problems/reverse-integer/

begin: 16:30
end:  17:18
Time complexity: O(logN) 
Space complexity: O(1)
*/
class Solution
{
public:
    int reverse(int x)
    {
        long long y = 0;
        while (x)
        {
            y = y*10 + x % 10;
            x /= 10;
        }
        if (y < -pow(2,31) || y > pow(2,31)-1)
            return 0;
        return y;
    }
};

int main()
{
    return 0;
}