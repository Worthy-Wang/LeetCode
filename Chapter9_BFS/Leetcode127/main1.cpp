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
题目：127. Word Ladder
链接：https://leetcode-cn.com/problems/word-ladder/

begin: 20:00
end:  20:34
Time complexity: O(N^2) 
Space complexity: O(N)
*/
class Solution
{
    vector<bool> visited;

public:
    void find_next_queue(vector<string> &wordList, string &word, queue<string> &next)
    {
        int len = word.size();
        for (int i = 0; i < wordList.size(); i++)
        {
            if (visited[i])
                continue;
            int diff = 0;
            for (int j = 0; j < len; j++)
            {
                if (word[j] != wordList[i][j])
                    diff++;
                if (diff > 1)
                    break;
            }
            if (diff == 1)
            {
                next.push(wordList[i]);
                visited[i] = true;
            }
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        visited.resize(wordList.size());
        int cnt = 0;
        queue<string> cur, next;
        cur.push(beginWord);
        while (!cur.empty())
        {
            cnt++;
            while (!cur.empty())
            {
                string word = cur.front();
                if (word == endWord)
                    return cnt;
                cur.pop();
                find_next_queue(wordList, word, next);
            }
            swap(cur, next);
        }
        return 0;
    }
};

int main()
{
    return 0;
}