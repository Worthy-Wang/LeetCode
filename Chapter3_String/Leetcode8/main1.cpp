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
题目：8. String to Integer (atoi)
链接：https://leetcode-cn.com/problems/string-to-integer-atoi/

begin: 14:00
end:  14:38
Time complexity: O(1) 
Space complexity: O(1)
*/
class Solution
{
public:
    int myAtoi(string str)
    {
        if (str.empty())
            return 0;
        stringstream ss(str);
        int i;
        ss >> i;
        return i;
    }
};

int main()
{
    return 0;
}