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
题目：3. Longest Substring Without Repeating Characters
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

begin: 15:34
end:  16:55
Time complexity: O(N^2) 
Space complexity: O(1)
*/

//滑动窗口算法
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;
        if (s.size() == 1)
            return 1;

        deque<char> window;
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (find(window.begin(), window.end(), s[i]) == window.end())
                window.push_back(s[i]);
            else
            {
                while (window.front() != s[i])
                    window.pop_front();
                window.pop_front();
                window.push_back(s[i]);
            }
            if (window.size() > maxLen)
                maxLen = window.size();
        }

        return maxLen;
    }
};

int main()
{
    Solution s;
    s.lengthOfLongestSubstring("pwwkew");
    return 0;
}