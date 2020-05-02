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
#include <stack>
using namespace std;

/*
题目：20. Valid Parentheses
链接：https://leetcode-cn.com/problems/valid-parentheses/

begin: 8:16
end:  8:26
Time complexity: O(N) 
Space complexity: O(1)
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> zh;
        for (auto& e: s)
        {
            if (zh.empty())
                zh.push(e);
            else
            {
                switch(zh.top())
                {
                    case '(':
                        e==')'?zh.pop():zh.push(e);
                        break;
                    case '[':
                        e==']'?zh.pop():zh.push(e);
                        break;
                    case '{':
                        e=='}'?zh.pop():zh.push(e);
                        break;
                    default:
                        break;
                }
            }
        }
        return zh.empty();
    }
};


int main()
{
    return 0;
}