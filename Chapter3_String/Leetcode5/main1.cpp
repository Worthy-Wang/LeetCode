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
#include <cctype>
using namespace std;

/*
题目：5. Longest Palindromic Substring
链接：https://leetcode-cn.com/problems/longest-palindromic-substring/

begin: 16:07
end:  17:46
Time complexity: O(N * N)
Space complexity: O(1)
*/

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return string();
        int N = s.size();
        int maxStart;
        int maxLen = 0;
        for (int cur = 0; cur < N; cur++)
        {
            int len = 1;
            int left = cur - 1, right = cur + 1;
            while (left >= 0 && s[left] == s[cur])
            {
                left--;
                len++;
            }
            while (right < N && s[right] == s[cur])
            {
                right++;
                len++;
            }
            while (left >= 0 && right < N && s[left] == s[right])
            {
                left--;
                right++;
                len += 2;
            }
            if (len > maxLen)
            {
                maxLen = len;
                maxStart = left + 1;
            }
        }
        return s.substr(maxStart, maxLen);
    }
};

int main()
{
    string str("babad");
    Solution s;
    s.longestPalindrome(str);
    return 0;
}
