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
#include <string>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
题目：93. Restore IP Addresses
链接：https://leetcode-cn.com/problems/restore-ip-addresses/

begin: 16:28
end:  18:11
Time complexity: O(N^4) 
Space complexity: O(N)
*/
class Solution
{
    vector<string> ans;

public:
    void DFS(const string &s, vector<string> path, int step)
    {
        if (path.size() == 4 && step == s.size())
        {
            ans.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            return;
        }

        for (int i = step + 1; i <= s.size(); i++)
        {
            string sub = s.substr(step, i - step);
            if (stoi(sub) > 255)
                break; //剪枝
            if (sub.size() > 1 && sub[0] == '0')
                break; //剪枝
            path.push_back(sub);
            DFS(s, path, i);
            path.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        if (s.size() > 12)
            return ans;
        vector<string> path;
        DFS(s, path, 0);
        return ans;
    }
};

int main()
{
    Solution s;
    s.restoreIpAddresses("25525511135");
    return 0;
}