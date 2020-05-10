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
class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
/*
题目：133. Clone Graph
链接：https://leetcode-cn.com/problems/clone-graph/

begin: 14:56
end:  15:42
Time complexity: O(N) 
Space complexity: O(N)
*/
//DFS算法
class Solution
{
    unordered_map<Node *, Node *> visited; //<旧节点， 新节点>
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;
        Node *root = new Node(node->val);
        visited[node] = root;
        vector<Node *> neighbors;
        for (int i = 0; i < node->neighbors.size(); i++)
        {
            if (visited.find(node->neighbors[i]) == visited.end())
                neighbors.push_back(cloneGraph(node->neighbors[i]));
            else
                neighbors.push_back(visited[node->neighbors[i]]);
        }
        root->neighbors = neighbors;
        return root;
    }
};

int main()
{
    return 0;
}