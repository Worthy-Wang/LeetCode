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
题目：121. Best Time to Buy and Sell Stock
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/

begin: 11:02
end:  13:37
Time complexity: O(N)
Space complexity: O(1)
*/
//双指针+贪心
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        int min_price = prices[0];
        int max_profit = 0; 
        for (int i = 1; i < prices.size(); i++)
        {
            min_price = min(min_price, prices[i]);
            max_profit = max(max_profit, prices[i] - min_price);
        }
        return max_profit;
    }
};

int main()
{
    return 0;
}