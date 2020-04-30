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
题目：38. Count and Say
链接：https://leetcode-cn.com/problems/count-and-say/

begin: 12:29
end:  13:59
Time complexity: O(N)
Space complexity: O(1)
*/
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string ans("1");
        for (int i = 2; i <= n; i++)
        {
            string temp;
            int cnt = 1;
            int number = ans[0] - '0';
            for (int k = 1; k < ans.size(); k++)
            {
                if (ans[k] == ans[k - 1])
                    cnt++;
                else
                {
                    temp.push_back(cnt + '0');
                    temp.push_back(number + '0');
                    number = ans[k] - '0';
                    cnt = 1;
                }
            }
            temp.push_back(cnt + '0');
            temp.push_back(number + '0');
            ans = temp;
        }
        return ans;
    }
};

int main()
{
    return 0;
}