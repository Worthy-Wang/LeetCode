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

begin: 13:52
end:  14：25
Time complexity:  O(2^N)
Space complexity: O(N)
*/

//DFS算法 合理但超时
class Solution
{
public:
    bool DFS(string& s, unordered_set<string>& hashset, int beg)
    {
        if (beg == s.size())
            return true;
        for (int i = beg; i < s.size(); i++)
        {
            string sub = s.substr(beg, i - beg + 1);
            if (hashset.find(sub) != hashset.end())
                if (DFS(s, hashset, i + 1))
                    return true;
        }
        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> hashset(wordDict.begin(), wordDict.end());
        return DFS(s, hashset, 0);
    }
};


int main()
{
    return 0;
}