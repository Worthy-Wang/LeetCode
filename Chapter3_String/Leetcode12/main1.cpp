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
题目：12. Integer to Roman
链接：https://leetcode-cn.com/problems/integer-to-roman/

begin: 9:46
end:  11:39
Time complexity: O(NlogN + N) 
Space complexity: O(N)
*/
class Solution
{
public:
    string intToRoman(int num)
    {
        map<int, string> mymap{{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
        string ans;
        for (auto rit = mymap.rbegin(); rit != mymap.rend(); rit++)
        {
            int count = num / rit->first;//加罗马数字的次数            
            for (; count > 0; count--) ans += rit->second;
            num %= rit->first;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    // cout << s.intToRoman(4) << endl;
    cout << 3 % 1 << endl;
    return 0;
}