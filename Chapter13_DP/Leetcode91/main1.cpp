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
题目：91. Decode Ways
链接：https://leetcode-cn.com/problems/decode-ways/

begin: 10:02
end:  
Time complexity: 
Space complexity: 
*/
//DFS 方法，超时
class Solution
{
    int cnt;
public:
    void DFS(string& s, vector<string>& path, int step)
    {
        if (step == s.size())
        {
            cnt ++;
            return;
        }

        for (int i = step; i < s.size(); i++)
        {
            string sub = s.substr(step, i - step + 1);
            if (sub[0] == '0')
                continue;//剪枝
            if (sub.size() >= 3 || stoi(sub) < 1 || stoi(sub) > 26)
                continue;//剪枝
            path.push_back(sub);
            DFS(s, path, i+1);
            path.pop_back();
        }
    }

    int numDecodings(string s)
    {
        if (s.empty())
            return 0;
        vector<string> path;
        cnt = 0;
        DFS(s, path, 0);
        return cnt;
    }
};

int main()
{
    return 0;
}