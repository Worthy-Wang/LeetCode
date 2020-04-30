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

begin: 11:39
end:  11:43
Time complexity: O(N) 
Space complexity: O(2*N)
*/
class Solution
{
public:
    string intToRoman(int num)
    {
        vector<int> first{1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> second{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        string ans;
        for (int i = first.size()-1; i >= 0; i--)
        {
            int count = num / first[i];
            for (; count > 0; count --) 
                ans += second[i];
            num %= first[i];
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