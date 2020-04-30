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

/*
题目：28. Implement strStr()
链接：https://leetcode-cn.com/problems/implement-strstr/

begin: 13:27
end:  13:55
Time complexity:  O(n*m)
Space complexity: O(1)
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int M = haystack.size(), N = needle.size();
        int len = M - N + 1;
        for (int k = 0; k < len; k++)
        {
            int i = k;
            int j = 0;
            for (; j < N; i++, j++)
                if (haystack[i] != needle[j])
                    break;
            if (j == N)
                return k;
        }
        return -1;
    }
};


int main()
{
    return 0;
}