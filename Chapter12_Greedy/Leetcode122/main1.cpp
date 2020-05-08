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
题目：122. Best Time to Buy and Sell Stock II
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/

begin: 15:14
end:  15：33
Time complexity: O(N)
Space complexity: O(1)
*/

//贪心算法,有利可图就卖
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        int sum = 0;
        for (int i = 1; i < prices.size(); i++)
            if (prices[i] > prices[i-1])
                sum += prices[i] - prices[i-1];        
        return sum;
    }
};

int main()
{
    return 0;
}