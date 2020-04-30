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
题目：14. Longest Common Prefix
链接：https://leetcode-cn.com/problems/longest-common-prefix/

begin: 18:25
end:  18:32
Time complexity: O(N) 
Space complexity: O(1)
*/
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return string();
        int len = 0;
        for (int j = 0; j < strs[0].size(); j++, len++)
            for (int i = 0; i < strs.size(); i++)
                if (strs[i][j] != strs[0][j])
                    return strs[0].substr(0, len);
        return strs[0].substr(0, len);
    }
};

int main()
{
    return 0;
}