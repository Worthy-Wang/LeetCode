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
题目：79. Word Search
链接：https://leetcode-cn.com/problems/word-search/

begin: 6:43 
end:  8:02
Time complexity: O(M^2 * N^2)
Space complexity: O(M*N)
*/
class Solution
{
public:
    bool DFS(vector<vector<char>> &board, int i, int j, vector<vector<bool>> &visited, string &word, int step)
    {
        if (step == word.size())
            return true;

        int m = board.size(), n = board[0].size();
        //退出条件
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;
        if (visited[i][j])
            return false;
        if (board[i][j] != word[step])
            return false;

        visited[i][j] = true;
        bool ret = DFS(board, i + 1, j, visited, word, step + 1) ||
                   DFS(board, i - 1, j, visited, word, step + 1) ||
                   DFS(board, i, j + 1, visited, word, step + 1) ||
                   DFS(board, i, j - 1, visited, word, step + 1);
        visited[i][j] = false;
        return ret;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (DFS(board, i, j, visited, word, 0))
                    return true;
        return false;
    }
};

int main()
{
    return 0;
}