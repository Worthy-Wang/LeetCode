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
题目：6. ZigZag Conversion
链接：https://leetcode-cn.com/problems/zigzag-conversion/

begin: 13:23
end:  14:19
Time complexity: O(N) 
Space complexity: O(numRows)
*/
//巧妙利用flag完成Z字形
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        int flag = -1;
        vector<string> ans(numRows);
        int k = 0;//ans的下标
        for (int i = 0; i < s.size(); i++)
        {
            if (k==0 || k == numRows-1)
                flag = - flag;
            ans[k] += s[i];
            k += flag;
        }

        string res;
        for (auto& e: ans)
            res += e;
        return res;
    }
};

int main()
{
    return 0;
}