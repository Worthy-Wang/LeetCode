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
题目：67. Add Binary
链接：https://leetcode-cn.com/problems/add-binary/

begin: 15:20
end:  15:29
Time complexity: O(N) 
Space complexity: O(N)
*/

class Solution
{
public:
    string addBinary(string a, string b)
    {
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        string ans;
        int carry = 0;
        int N = std::max(a.size(), b.size());
        for (int k = 0; k < N; k++)
        {
            int i = (k < a.size() ? a[k]-'0' : 0);
            int j = (k < b.size() ? b[k]-'0' : 0);
            int sum = i + j + carry;
            carry = (sum>=2 ? 1 : 0);
            char c = (sum % 2 ? '1' : '0');
            ans.push_back(c);
        }
        if (carry)
            ans.push_back('1');
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    string a("11");
    string b("1");
    Solution s;
    cout << s.addBinary(a, b) << endl;
    return 0;
}