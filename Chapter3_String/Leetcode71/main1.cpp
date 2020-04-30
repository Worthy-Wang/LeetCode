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
#include <regex>
using namespace std;

/*
题目：71. Simplify Path
链接：https://leetcode-cn.com/problems/simplify-path/

begin: 14:41
end:  20:00
Time complexity: O(N) 
Space complexity: O(N)
*/

class Solution
{
public:
    string simplifyPath(string path)
    {
        deque<string> que;
        for (auto it = path.begin(); it != path.end();)
        {
            if (*it != '/')
            {
                auto j = std::find(it, path.end(), '/');
                string s(it, j);
                if (s != ".")
                {
                    if (s == "..")
                    {
                        if (!que.empty())
                            que.pop_back();
                    }
                    else
                        que.push_back(s);
                }
                it = j;
            }
            else
                it ++;
        }

        stringstream ss;
        if (que.empty())
            ss << "/";
        else
        {
            while (!que.empty())
            {
                ss << "/" << que.front();
                que.pop_front();
            }
        }
        return ss.str();
    }
};

int main()
{
    Solution s;
    cout << s.simplifyPath("/a//b////c/d//././/..") << endl;
    return 0;
}