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

begin: 11:14 
end:  13:26
Time complexity: O(N) 
Space complexity: O(1)
*/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        auto l = s.begin();
        auto r = std::prev(s.end());
        while (l < r)
        {
            if (!isalnum(*l)) 
                l++;
            else if (!isalnum(*r))
                r--;
            else if (tolower(*l) != tolower(*r))
                return false;
            else
                l++, r--;
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