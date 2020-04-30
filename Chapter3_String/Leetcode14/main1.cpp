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

begin: 17:48
end:  18:06
Time complexity: O(n^2) 
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
        int minSize = INT_MAX;
        for (int i = 0; i < strs.size(); i++)
            if (strs[i].size() < minSize)
                minSize = strs[i].size();
        for (int j = 0; j < minSize; j++)
        {
            char ch = strs[0][j];
            for (int i = 0; i < strs.size(); i++)
                if (strs[i][j] != ch)
                    return strs[0].substr(0, len);
            len++;
        }
        return strs[0].substr(0, len);
    }
};

int main()
{
    return 0;
}