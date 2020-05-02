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
#include <stack>
#include <queue>
#include <deque>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
题目：96. Unique Binary Search Trees
链接：https://leetcode-cn.com/problems/unique-binary-search-trees/

begin: 16:17
end:  17:04
Time complexity: O(N^2) 
Space complexity: O(N)
*/

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> fn(n+1);
        fn[0] = 1;
        fn[1] = 1;
        if (n < 2)
            return fn[n];

        for (int k = 2; k <= n; k++)
        {
            int sum = 0;
            for (int i = 0; i < k; i++)
                sum += fn[i] * fn[k-i-1];
            fn[k] = sum;
        }               
        return fn[n]; 
    }
};

int main()
{
    Solution s;
    cout << s.numTrees(3) << endl;
    return 0;
}