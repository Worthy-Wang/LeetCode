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
题目：13. 罗马数字转整数
链接：https://leetcode-cn.com/problems/roman-to-integer/

begin: 11:44
end:  12:27
Time complexity: O(N) 
Space complexity: O(1)
*/
class Solution
{
public:
    int convert(char c)
    {
        switch(c)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }

    int romanToInt(string s)
    {
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int n = convert(s[i]);
            sum += n;
            if (i+1 < s.size() && convert(s[i+1]) > n)
                sum -= 2* n;
        }
        return sum;
    }
};

int main()
{
    return 0;
}