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
题目：55. Jump Game
链接：https://leetcode-cn.com/problems/jump-game/

begin: 10:33
end:  10:51
Time complexity: O(N) 
Space complexity: O(1)
*/
//正向跳楼梯
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++)
        {   
            if (maxIndex >= i)
                maxIndex = max(nums[i] + i, maxIndex);
        }
        return maxIndex >= nums.size() - 1;
    }
};


int main()
{
    return 0;
}