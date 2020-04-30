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

begin: 14:39
end:  15:15
Time complexity: O(max(M,N)) 
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
        for (int i = 0, j = 0; i < a.size() || j < b.size(); i++, j++)
        {
            int sum = 0;
            if (i < a.size() && j < b.size())
            {
                sum = a[i]-'0' + b[j]-'0' + carry;
                ans.push_back(sum % 2? '1' : '0');
            }
            else if (i < a.size())
            {
                sum = a[i]-'0' + carry;
                ans.push_back(sum % 2? '1' : '0');
            }
            else
            {
                sum = b[j]-'0' + carry;
                ans.push_back(sum % 2? '1' : '0');
            }
            sum >= 2 ? carry = 1 : carry = 0;
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