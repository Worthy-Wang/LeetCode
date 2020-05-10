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
#include <sstream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
题目：43. Multiply Strings
链接：https://leetcode-cn.com/problems/multiply-strings/

begin: 8:36
end:  9:40
Time complexity: O(N^2)
Space complexity: O(1)
*/
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> temp(num1.size() + num2.size(), 0);
        for (int i = 0; i < num1.size(); i++)
            for (int j = 0; j < num2.size(); j++)
                temp[i + j] += (num1[i] - '0') * (num2[j] - '0');
        //统一进位
        int i;
        for (i = 0; i < temp.size() - 1; i++)
        {
            temp[i+1] += temp[i] / 10;
            temp[i] = temp[i] % 10;
        }
        temp[i] = temp[i] % 10;
        //转换成字符串
        string ans;
        for (i = 0; i < temp.size(); i++)
            ans += to_string(temp[i]);
        reverse(ans.begin(), ans.end());
        //去掉头部的0
        while (ans[0] == '0')
            ans.erase(ans.begin());
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.multiply("123", "456") << endl;
    return 0;
}