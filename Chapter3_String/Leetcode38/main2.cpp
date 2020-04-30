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
#include <sstream>
using namespace std;

/*
题目：38. Count and Say
链接：https://leetcode-cn.com/problems/count-and-say/

begin: 14:00
end:  14:35
Time complexity: O(N^2)
Space complexity: O(1)
*/
class Solution
{
public:
    string next(string s)
    {
        stringstream ss;
        for (auto l = s.begin(), r = s.begin(); l != s.end(); l = r)
        {
            r = std::find_if(l, s.end(), std::bind1st(std::not_equal_to<char>(), *l));
            ss << std::distance(l, r) << *l;
        }
        return ss.str();
    }

    string countAndSay(int n)
    {
        string ans("1");
        for (int i = 1; i < n; i++)
            ans = next(ans);
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.countAndSay(4) << endl;
    return 0;
}