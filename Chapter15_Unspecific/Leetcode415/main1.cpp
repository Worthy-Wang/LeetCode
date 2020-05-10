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
题目：415. Add Strings
链接：https://leetcode-cn.com/problems/add-strings/

begin: 8:20
end:  8:33
Time complexity: O(max(M, N)) 
Space complexity: O(1)
*/
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string ans;
        while (carry || i >= 0 || j >= 0)
        {
            int x = i >= 0 ? num1[i--] - '0' : 0;
            int y = j >= 0 ? num2[j--] - '0' : 0;
            ans.insert(0, to_string((x + y + carry) % 10));
            carry = (x + y + carry) / 10;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.addStrings("1", "9");
    return 0;
}