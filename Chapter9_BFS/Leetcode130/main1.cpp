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
题目：130. Surrounded Regions
链接：https://leetcode-cn.com/problems/surrounded-regions/

begin: 9:46
end:  10:49
Time complexity: O(N^2)
Space complexity: O(N)
*/
class Solution
{
public:
    void BFS(vector<vector<bool>> &visited, vector<vector<char>> &board, const pair<int, int> &pos, int M, int N)
    {
        queue<pair<int, int>> cur, next;
        cur.push(pos);
        visited[pos.first][pos.second] = true;
        while (!cur.empty())
        {
            while (!cur.empty())
            {
                pair<int, int> node = cur.front();
                cur.pop();
                int i = node.first, j = node.second;
                //find_next_que
                if (i + 1 < M && !visited[i + 1][j] && board[i + 1][j] == 'O')
                {
                    next.push(make_pair(i + 1, j));
                    visited[i + 1][j] = true;
                }
                if (i - 1 >= 0 && !visited[i - 1][j] && board[i - 1][j] == 'O')
                {
                    next.push(make_pair(i - 1, j));
                    visited[i - 1][j] = true;
                }
                if (j + 1 < N && !visited[i][j + 1] && board[i][j + 1] == 'O')
                {
                    next.push(make_pair(i, j + 1));
                    visited[i][j + 1] = true;
                }
                if (j - 1 >= 0 && !visited[i][j - 1] && board[i][j - 1] == 'O')
                {
                    next.push(make_pair(i, j - 1));
                    visited[i][j - 1] = true;
                }
            }
            swap(cur, next);
        }
    }

    void solve(vector<vector<char>> &board)
    {
        if (board.empty())
            return;
        int M = board.size();
        int N = board[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N));

        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (i == 0 || j == 0 || i == M - 1 || j == N - 1)
                    if (!visited[i][j] && board[i][j] == 'O')
                        BFS(visited, board, make_pair(i, j), M, N);

        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (visited[i][j])
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
    }
};

int main()
{
    return 0;
}