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
题目：131. Palindrome Partitioning
链接：https://leetcode-cn.com/problems/palindrome-partitioning/

begin: 13:28
end:  14:30
Time complexity: O(2^n)
Space complexity: O(N)
*/
class Solution
{
    vector<vector<string>> ans;

public:
    bool is_palindrome(const string &s)
    {
        for (auto l = s.begin(), r = prev(s.end()); l <= r; l++, r--)
            if (*l != *r)
                return false;
        return true;
    }

    void DFS(const string &s, vector<string> &path, int step)
    {
        if (step == s.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = 1; i <= s.size() - step; i++)
        {
            string sub = s.substr(step, i);
            if (is_palindrome(sub))
            {
                path.push_back(sub);
                DFS(s, path, step + i);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<string> path;
        DFS(s, path, 0);
        return ans;
    }
};

int main()
{
    Solution s;
    s.partition("aab");
    return 0;
}