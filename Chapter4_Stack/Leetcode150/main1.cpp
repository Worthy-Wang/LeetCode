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
#include <queue>
#include <deque>
using namespace std;

/*
题目：150. Evaluate Reverse Polish Notation
链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/

begin: 8:44
end:  9:30
Time complexity: O(N) 
Space complexity: O(N) 不确定
*/
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;
        for (auto &e : tokens)
        {
            if (is_operator(e))
            {
                int right = stk.top();
                stk.pop();
                int left = stk.top();
                stk.pop();
                int ret;
                char ope = e[0];
                switch(ope)
                {
                    case '+': ret = left + right;break;
                    case '-': ret = left - right;break;
                    case '*': ret = left * right;break;
                    case '/': ret = left / right;break;
                }
                stk.push(ret);
            }
            else
                stk.push(stoi(e));
        }
        return stk.top();
    }

private:
    bool is_operator(const string &s) const
    {
        return s.size()==1 && string("+-*/").find(s)!=string::npos;
    }
};

int main()
{
    vector<string> vec{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution s;
    cout << s.evalRPN(vec) << endl;
    return 0;
}