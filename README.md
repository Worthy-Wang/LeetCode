# Leetcode 专题训练

------------
解题程序都放在Github中：（持续更新）

---------------------------
# 刷题之前，用三分钟看看下面的东西，相信我，会有帮助的
### 在进行Leetcode的训练之前，应该掌握：
* 一种主流语言（如C++/Java等）
如果你不熟悉语言，可能你无法理解像`sort`, `merge`, `bind`，这些STL库函数在算法中的妙用 ， 也无法理解`vector` 或是 `queue`这些容器库的方便之处。
* 熟悉数据结构与算法
如果你不熟悉数据结构，那么像`二叉树`，`BST`，`AVL`树这些看似简单的结构都会让你头疼很久；更不用说在图论中出现的`DFS`, `BFS`, `贪心算法`，`动态规划`等。

未掌握好以上两点就刷Leetocde， 那么你可能每一题都需要`两三个小时`才能完成。
<br>

### 做题套路
* `分专题`（Github中的专题分类）

这样你才能更好的掌握某一类专题的套路，**题是做不完的，但是专题可以做完！**
<br>



### 做题方法：
* `一刷`十分钟做不出来直接看答案，有些题的思路第一次真的想不到
* `二刷`开始就需要自己做出来，因为第一次你已经有印象了
* `再接下来`的训练中，保证能快速做出来，毕竟面试时间就一点
* `每周`参加Leetocde周赛，保持手感
<br>


### Github中的做题格式：（以118题为例）
* 标明做题的`开始时间`与`通过时间`

这样会让你知道每做一道题花了多少时间

* 标明`时间复杂度` 与 `空间复杂度`

习惯之后你才能明白哪些算法效率高

```cpp
题目：118. Pascal's Triangle
链接：https://leetcode-cn.com/problems/pascals-triangle/

begin: 9:42
end:  9:56
Time complexity: O(N^2) 
Space complexity: O(1)
```

```cpp
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> temp(i+1, 1);
            ans.push_back(temp);
            for (int j = 0; j <= i; j++)
                if (i > 0 && j > 0 && j < i)
                    ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        return ans;
    }
};
```
<br>

# 下面是Github中的专题分类方式：


* 专题一：数组(`Chapter1_Array`)
* 专题二：链表(`Chapter2_list`)
* 专题三：字符串(`Chapter3_String`)
* 专题四：栈(`Chapter4_Stack`)
* 专题五：树(`Chapter5_Tree`)
* 专题六：排序(`Chapter6_Sort`)
* 专题七：查找(`Chapter7_Search`)
* 专题八：暴力解法(`Chapter8_Violence`)
* 专题九：BFS(`Chapter9_BFS`)
* 专题十：DFS(`Chapter10_DFS`)
* 专题十一：分治(`Chapter11_Paritition`)
* 专题十二：贪心(`Chapter12_Greedy`)
* 专题十三：动态规划(`Chapter13_DP`)
* 专题十四：图(`Chapter14_Graph`)
* 专题十五：不定类型(`Chapter15_Unspecific`)
