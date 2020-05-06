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
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
题目：17. Letter Combinations of a Phone Number
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/

begin: 18:01
end:  18:47
Time complexity: O() 
Space complexity: 
*/
class Solution
{
    vector<string> ans;
public:
    void DFS(string& digits,  vector<string>& numbers, int step, string& path)
    {
        if (step == digits.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < numbers[digits[step]-'0'].size(); i++)
        {
            path.push_back(numbers[digits[step]-'0'][i]);
            DFS(digits, numbers, step+1, path);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return ans;
        vector<string> numbers{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string path;        
        DFS(digits, numbers, 0, path);
        return ans;
    }
};

int main()
{
    return 0;
}