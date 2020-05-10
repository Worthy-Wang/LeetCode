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
#include <queue>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
题目：9. Palindrome Number
链接：https://leetcode-cn.com/problems/palindrome-number/

begin: 17:20
end:  17:24
Time complexity: O(N) 
Space complexity: O(1)
*/
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        string s = to_string(x);
        for (int i = 0, j = s.size()-1; i < j; i++, j--)
            if (s[i] != s[j])
                return false;
        return true;
    }
};


int main()
{
    return 0;
}