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
题目：139. Word Break
链接：https://leetcode-cn.com/problems/word-break/

begin: 14:29
end:  14:54
Time complexity:  O(N^2)
Space complexity: O(N)
*/

//动态规划 dp
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> hashset(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
            for (int j = i - 1; j >= 0; j--)
                if (dp[j] == true)
                    if (hashset.find(s.substr(j, i - j)) != hashset.end())
                    {
                        dp[i] = true;
                        break;
                    }
        return dp[s.size()];
    }
};

int main()
{
    return 0;
}