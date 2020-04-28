#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

/*
STL
Time complexity: O(N)
Space complexity: O(1)
*/
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        return std::distance(nums.begin(), std::unique(nums.begin(), nums.end()));
    }
};



int main()
{
    vector<int> vec{1,1,2};
    Solution s;
    cout << s.removeDuplicates(vec) << endl;
    return 0;
}