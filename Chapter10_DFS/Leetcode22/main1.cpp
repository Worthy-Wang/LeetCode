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
题目：22. Generate Parentheses
链接：https://leetcode-cn.com/problems/generate-parentheses/

begin: 21:20
end:  22:54
Time complexity: O()
Space complexity: O(N)
*/
//关键思路：path 路径中 左括号 恒 >= 右括号的数
class Solution
{
    vector<string> ans;

public:
    void DFS(string &path, int l, int r, int n)
    {
        if (path.size() == 2 * n)
        {
            ans.push_back(path);
            return;
        }

        //左括号
        if (l < n)
        {
            path.push_back('(');
            DFS(path, l+1, r, n);
            path.pop_back();
        }

        //右括号
        if (l > r)
        {
            path.push_back(')');
            DFS(path, l, r+1, n);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        string path;
        DFS(path, 0, 0, n);
        return ans;
    }
};

int main()
{

    return 0;
}