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
题目：58. Length of Last Word
链接：https://leetcode-cn.com/problems/length-of-last-word/

begin: 20:06
end:  20:09
Time complexity: O(1) 
Space complexity: O(1)
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty())
            return 0;
        stringstream ss(s);
        string ans;
        while (ss)
            ss >> ans;
        return ans.size();
    }
};



int main()
{

    return 0;
}