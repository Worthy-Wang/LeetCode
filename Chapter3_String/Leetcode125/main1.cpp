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
题目：125. Valid Palindrome
链接：https://leetcode-cn.com/problems/valid-palindrome/

begin: 10:21
end:  11:07
Time complexity: O(N) 
Space complexity: O(1)
*/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;

        while (l < r)
        {
            while (l < r && !isalnum(s[l]))
                l++;
            while (l < r && !isalnum(s[r]))
                r--;
            if (l < r)
            {
                if (tolower(s[l]) != tolower(s[r]))
                    return false;
                l++, r--;
            }
        }
        return true;
    }
};

int main()
{
    string s("0P");
    Solution so;
    cout << so.isPalindrome(s) << endl;
    return 0;
}